#include "Squinky.hpp"
#include "ctrl/SqHelper.h"

const NVGcolor SqHelper::COLOR_GREY = nvgRGB(0x80, 0x80, 0x80);
const NVGcolor SqHelper::COLOR_WHITE = nvgRGB(0xff, 0xff, 0xff);
const NVGcolor SqHelper::COLOR_BLACK = nvgRGB(0,0,0);
const NVGcolor SqHelper::COLOR_SQUINKY = nvgRGB(0x30, 0x7d, 0xee);

#if defined(METAMODULE_BUILTIN)
extern Plugin *pluginInstance;
#else
Plugin *pluginInstance;
#endif

#if defined(METAMODULE_BUILTIN)
void init_SquinkyLabs(rack::Plugin *p) {
#else 
void init(rack::Plugin *p) {
#endif
  pluginInstance = p;

  p->addModel(modelFiltModule);
  p->addModel(modelEV3Module);
  // p->addModel(modelCompressorModule);
  // p->addModel(modelCompressor2Module);
  // p->addModel(modelBasicModule);
  // p->addModel(modelBootyModule);
  // p->addModel(modelCHBModule);
  // Chopper
  // p->addModel(modelTremoloModule);
}