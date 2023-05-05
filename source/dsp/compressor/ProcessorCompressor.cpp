//
//  ProcessorCompressor.cpp
//  VAESynth
//
//  Created by Fares Schulz on 17.03.23.
//

#include "ProcessorCompressor.h"

ProcessorCompressor::ProcessorCompressor(juce::AudioProcessorValueTreeState &apvts): compressor(){
    compressor.setThreshold(apvts.getRawParameterValue(PluginParameters::COMP_THRESHOLD_ID.getParamID())->load());
    compressor.setRatio(apvts.getRawParameterValue(PluginParameters::COMP_RATIO_ID.getParamID())->load());
    compressor.setMakeUpGain(apvts.getRawParameterValue(PluginParameters::COMP_MAKEUPGAIN_ID.getParamID())->load());
}

ProcessorCompressor::~ProcessorCompressor() = default;

void ProcessorCompressor::prepare(const juce::dsp::ProcessSpec &spec){
    compressor.prepare(spec);
}

void ProcessorCompressor::processBlock(juce::AudioBuffer<float>& buffer){
    compressor.processBlock(buffer);
}

void ProcessorCompressor::parameterChanged(const juce::String &parameterID, float newValue){
    if (parameterID == PluginParameters::COMP_THRESHOLD_ID.getParamID()) {
        compressor.setThreshold(newValue);
    } else if (parameterID == PluginParameters::COMP_RATIO_ID.getParamID()) {
        compressor.setRatio(newValue);
    } else if (parameterID == PluginParameters::COMP_MAKEUPGAIN_ID.getParamID()) {
        if (newValue == -0.1f){
            compressor.setAutoMakeUpGain(true);
        }
        else {
            compressor.setAutoMakeUpGain(false);
            compressor.setMakeUpGain(newValue);
        }
    }
}
