/*
  ==============================================================================

    lowpasshighpassprocessor.h
    Created: 30 Jun 2022 9:03:38pm
    Author:  RAZER_BLADE

  ==============================================================================
*/

#pragma once
#include <vector>
#include "JuceHeader.h"

using namespace juce;
class lowpasshighpassprocessor {
public:
	void SetCutOffFrequency(float cutOffFrequency);
	void SetSamplingRate(float samplingRate);
	void SetHighPass(bool highPass);
	void ProcessBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiBuffer);
protected:


private:
	bool highPass;
	float samplingRate;
	float cutOffFrequency;

	std::vector<float> dnBuffer;
};
