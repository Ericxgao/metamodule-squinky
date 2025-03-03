#pragma once

// Prevent standard headers from being included
#define _LIBCPP_MUTEX
#define _LIBCPP_CONDITION_VARIABLE
#define _GLIBCXX_MUTEX 
#define _GLIBCXX_CONDITION_VARIABLE
#define _GLIBCXX_THREAD
#define _LIBCPP_THREAD

#include <memory> // for std::unique_ptr

namespace std {

struct mutex {
	mutex() = default;
	~mutex() = default;
	
	void lock() {}
	void unlock() {}
	bool try_lock() { return true; }
	
	// Delete copy and move operations
	mutex(const mutex&) = delete;
	mutex& operator=(const mutex&) = delete;
};

struct condition_variable {
	condition_variable() = default;
	~condition_variable() = default;
	
	void notify_one() noexcept {}
	void notify_all() noexcept {}
	
	template<typename Predicate>
	void wait(mutex& lock, Predicate pred) {
		while (!pred()) {
			// No-op wait
		}
	}
	
	void wait(mutex& lock) {}
	
	// Delete copy and move operations
	condition_variable(const condition_variable&) = delete;
	condition_variable& operator=(const condition_variable&) = delete;
};

template<typename Mutex>
struct lock_guard {
	explicit lock_guard(Mutex& m) : mutex_(m) {
		mutex_.lock();
	}
	
	~lock_guard() {
		mutex_.unlock();
	}
	
	lock_guard(const lock_guard&) = delete;
	lock_guard& operator=(const lock_guard&) = delete;
	
private:
	Mutex& mutex_;
};

template<typename Mutex>
struct unique_lock {
	explicit unique_lock(Mutex& m) : mutex_(&m), locked_(true) {
		mutex_->lock();
	}
	
	~unique_lock() {
		if (locked_ && mutex_) {
			mutex_->unlock();
		}
	}
	
	void unlock() {
		if (locked_ && mutex_) {
			mutex_->unlock();
			locked_ = false;
		}
	}
	
	void lock() {
		if (!locked_ && mutex_) {
			mutex_->lock();
			locked_ = true;
		}
	}
	
	unique_lock(const unique_lock&) = delete;
	unique_lock& operator=(const unique_lock&) = delete;
	
private:
	Mutex* mutex_;
	bool locked_;
};

class thread {
public:
	thread() = default;
	
	template<typename Function, typename... Args>
	explicit thread(Function&& f, Args&&... args) {
		// No-op constructor, won't actually create a thread
	}
	
	~thread() = default;
	
	void join() {}
	void detach() {}
	bool joinable() const { return false; }
	
	thread(thread&&) noexcept = default;
	thread& operator=(thread&&) noexcept = default;
	
	thread(const thread&) = delete;
	thread& operator=(const thread&) = delete;
};

} // namespace std