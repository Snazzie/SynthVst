/*
  ==============================================================================

    SliderWithLabel.h
    Created: 8 May 2019 10:55:25pm
    Author:  acoop

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

class SliderWithLabel : public Component
{
public:

	SliderWithLabel()
	{
		setSize(80, 200);
		slider.setSize(50, 50);
		slider.setNumDecimalPlacesToDisplay(0);
		label.setSize(50, 20);
		addAndMakeVisible(slider, 1);
		addAndMakeVisible(label, 0);
	}
	void paint(Graphics&) override
	{
		
	}
	void resized() override
	{
		slider.setBounds(0,0,70,70);
		label.centreWithSize(80,100);
		Point<int> pos = label.getPosition();
		label.setBounds(pos.x, pos.y +65, 50, 20);
	}


	Slider slider;
	Label label;
};