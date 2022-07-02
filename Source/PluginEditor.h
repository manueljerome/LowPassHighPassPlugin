/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class LowPassHighPassPluginAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    LowPassHighPassPluginAudioProcessorEditor(LowPassHighPassPluginAudioProcessor&, juce::AudioProcessorValueTreeState& vts);
    ~LowPassHighPassPluginAudioProcessorEditor() override;

    //==============================================================================
    void paint(juce::Graphics&) override;
    void resized() override;
    const juce::String cutOffFrequency{ "CutOff_Frequency" };
    const juce::String cutOffFrequencyLabelText{ "CutOff Frequency" };
    const juce::String HighPassID{ "highpass" };
    const juce::String HighPassLabel{ "High_Pass" };

private:
    juce::Slider cutoffFrequencySlider;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>
        cutoffFrequencyAttachment;
    juce::Label cutoffFrequencyLabel;
    juce::ToggleButton highpassButton;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment>
        highpassAttachment;
    juce::Label highpassButtonLabel;
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    LowPassHighPassPluginAudioProcessor& audioProcessor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LowPassHighPassPluginAudioProcessorEditor)
};
