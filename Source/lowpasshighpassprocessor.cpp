/*
  ==============================================================================

    lowpasshighpassprocessor.cpp
    Created: 30 Jun 2022 9:23:01pm
    Author:  RAZER_BLADE

  ==============================================================================
*/

#include "lowpasshighpassprocessor.h"
void lowpasshighpassprocessor::SetCutOffFrequency(float cutOffFrequency)
{
	this->cutOffFrequency = cutOffFrequency;
}

void lowpasshighpassprocessor::SetSamplingRate(float samplingRate)
{
	this->samplingRate = samplingRate;
}

void lowpasshighpassprocessor::SetHighPass(bool highPass)
{
	this->highPass = highPass;
}

void lowpasshighpassprocessor::ProcessBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiBuffer)
{
	constexpr float pi = 3.14159265359f;

	dnBuffer.resize(buffer.getNumChannels(), 0.f);

	float sign = highPass ? -1.0f : 1.0f;

	const auto tan = std::tan(pi * cutOffFrequency / samplingRate);
	const auto a1 = tan - 1.f / tan + 1.f;

	for (auto channel{ 0 }; channel < buffer.getNumChannels(); channel++) {
		auto channelSamples = buffer.getWritePointer(channel);
		for (auto sample{ 0 }; sample < buffer.getNumSamples(); sample++) {
			auto inputSample = channelSamples[sample];
			auto allPassFilteredSamples = inputSample * a1 + dnBuffer[channel];
			dnBuffer[channel] = inputSample - a1 * allPassFilteredSamples;
			const auto filteredOutput = 0.5f * (inputSample + sign * allPassFilteredSamples);
			channelSamples[sample] = filteredOutput;
		}
	}
}