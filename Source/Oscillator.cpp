/*
  ==============================================================================

	Oscillator.cpp
	Created: 5 May 2019 5:58:52pm
	Author:  acoop

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(NewProjectAudioProcessor& p) : processor(p)
{
	setSize(200, 200);

	StringArray types = StringArray({ "Sine","Saw","Square" });
	for (int i = 0; i < types.size(); i++)
	{
		oscMenu.addItem(types[i], i + 1); // + 1 because Juce treats 1 as start of array, this will normalize to 0 when sent to processor
	}
	oscMenu.setJustificationType(Justification::centred);

	addAndMakeVisible(&oscMenu);
	oscMenu.addListener(this);

	waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "waveType", oscMenu); // make connection 

}

Oscillator::~Oscillator()
{
}

void Oscillator::paint(Graphics & g)
{

	g.fillAll(getLookAndFeel().findColour(ResizableWindow::backgroundColourId));   // clear the background
}

void Oscillator::resized()
{
	Rectangle<int> area = getLocalBounds().reduced(40, 40);
	oscMenu.setBounds(area.removeFromTop(20));

}

void Oscillator::comboBoxChanged(ComboBox * comboBoxThatHasChanged)
{

}
