/*
  ==============================================================================

	Envelope.cpp
	Created: 6 May 2019 12:14:37am
	Author:  acoop

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"
#include "PluginProcessor.h"

//==============================================================================
Envelope::Envelope(NewProjectAudioProcessor& p) : processor(p)
{
	// In your constructor, you should add any child components, and
	// initialise any special settings that your component needs.
		//slider initialization values

	attackSlider.slider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	attackSlider.slider.setRange(0.1f, 5000.0f);
	attackSlider.slider.setValue(0.1f);
	attackSlider.slider.setTextBoxStyle(Slider::TextBoxAbove, true, 80, 20);
	attackSlider.slider.addListener(this);
	attackSlider.label.setText("Attack", NotificationType::dontSendNotification);
	addAndMakeVisible(&attackSlider);

	decaySlider.slider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	decaySlider.slider.setRange(1.0f, 2000.0f);
	decaySlider.slider.setValue(1.0f);
	decaySlider.slider.setTextBoxStyle(Slider::TextBoxAbove, true, 80, 20);
	decaySlider.slider.addListener(this);
	decaySlider.label.setText("Decay", NotificationType::dontSendNotification);
	addAndMakeVisible(&decaySlider);

	sustainSlider.slider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	sustainSlider.slider.setRange(0.0f, 1.0f);
	sustainSlider.slider.setValue(0.8f);
	sustainSlider.slider.setTextBoxStyle(Slider::TextBoxAbove, true, 80, 20);
	sustainSlider.slider.addListener(this);
	sustainSlider.label.setText("Sustain", NotificationType::dontSendNotification);
	addAndMakeVisible(&sustainSlider);

	releaseSlider.slider.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
	releaseSlider.slider.setRange(0.1f, 5000.0f);
	releaseSlider.slider.setValue(0.8f);
	releaseSlider.slider.setTextBoxStyle(Slider::TextBoxAbove, true, 80, 20);
	releaseSlider.slider.addListener(this);
	releaseSlider.label.setText("release", NotificationType::dontSendNotification);
	addAndMakeVisible(&releaseSlider);

	//sends value of the sliders to the tree state in the processor
	attackVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attackSlider.slider);
	decayVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay", decaySlider.slider);
	sustainVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain", sustainSlider.slider);
	releaseVal = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release", releaseSlider.slider);
}

void Envelope::sliderValueChanged(Slider* slider)
{
}

Envelope::~Envelope()
{
}

void Envelope::paint(Graphics& g)
{
	/* This demo code just fills the component's background and
	   draws some placeholder text to get you started.

	   You should replace everything in this method with your own
	   drawing code..
	*/

	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));   // clear the background
}

void Envelope::resized()
{
	// This method is where you should set the bounds of any child
	// components that your component contains..

	Rectangle<int> area = getLocalBounds().reduced(20, 20);
	
	float SizeX = attackSlider.getX();
	float SizeY = attackSlider.getY();
	float bottom = area.removeFromBottom(0).getY()-80;
	float left = area.removeFromLeft(0).getX();
	attackSlider.setBounds(left, bottom, 100, 100);

	decaySlider.setBounds(left + 80, bottom, 100, 100);
	sustainSlider.setBounds(left + (80 *2), bottom, 100, 100);
	releaseSlider.setBounds(left + (80 * 3), bottom, 100, 100);

}
