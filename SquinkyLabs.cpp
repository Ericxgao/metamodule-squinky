#include "Squinky.hpp"
#include "ctrl/SqHelper.h"

const NVGcolor SqHelper::COLOR_GREY = nvgRGB(0x80, 0x80, 0x80);
const NVGcolor SqHelper::COLOR_WHITE = nvgRGB(0xff, 0xff, 0xff);
const NVGcolor SqHelper::COLOR_BLACK = nvgRGB(0,0,0);
const NVGcolor SqHelper::COLOR_SQUINKY = nvgRGB(0x30, 0x7d, 0xee);

int soloStateCount = 0;

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
  p->addModel(modelF2Module);
  p->addModel(modelCompressorModule);
  p->addModel(modelVocalFilterModule);
  p->addModel(modelGrayModule);
  p->addModel(modelSuperModule);
  //p->addModel(modelColoredNoiseModule);
  p->addModel(modelShaperModule);
  p->addModel(modelVocalModule);  
  p->addModel(modelCHBModule);
  p->addModel(modelLFNModule); 
  // p->addModel(modelLFNBModule); 
  p->addModel(modelBasicModule);
  p->addModel(modelBootyModule);
  p->addModel(modelTremoloModule);  
  p->addModel(modelSlew4Module);
  p->addModel(modelMix8Module);
  p->addModel(modelMixMModule);
  p->addModel(modelFunVModule);
  p->addModel(modelDrumTriggerModule);
  p->addModel(modelMixStereoModule);
  p->addModel(modelWVCOModule);
  p->addModel(modelSubModule);
  p->addModel(modelSinesModule);
  // p->addModel(modelSampModule);
}