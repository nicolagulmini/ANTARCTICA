#include "PluginProcessor.h"
#include "PluginEditor.h"

ANTARCTICAAudioProcessorEditor::ANTARCTICAAudioProcessorEditor (ANTARCTICAAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    
    gainSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, GAIN_ID, gainSlider);
    setCustomSliderStyle(gainSlider, 2, GAIN_NAME);

    clipperSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, CLIPPER_ID, clipperSlider);
    setCustomSliderStyle(clipperSlider, 2, CLIPPER_NAME);

    saturationSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, SATURATION_ID, saturationSlider);
    setCustomSliderStyle(saturationSlider, 2, SATURATION_NAME);

    distSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DRIVE_ID, distSlider);
    setCustomSliderStyle(distSlider, 2, DRIVE_NAME);

    bitSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, BIT_ID, bitSlider);
    setCustomSliderStyle(bitSlider, 2, BIT_NAME);

    downSampleSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DWNSMP_ID, downSampleSlider);
    setCustomSliderStyle(downSampleSlider, 2, DWNSMP_NAME);

    drywetSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DRYWET_ID, drywetSlider);
    setCustomSliderStyle(drywetSlider, 2, DRYWET_NAME);

    antialiasingSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, ANTIALIASING_ID, antialiasingSlider);
    setCustomSliderStyle(antialiasingSlider, 2, ANTIALIASING_NAME);

    inputSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, INPUT_ID, inputSlider);
    setCustomSliderStyle(inputSlider, 1, INPUT_NAME);

    outputSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, OUTPUT_ID, outputSlider);
    setCustomSliderStyle(outputSlider, 1, OUTPUT_NAME);

    delayAmountSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DELAYAMOUNT_ID, delayAmountSlider);
    setCustomSliderStyle(delayAmountSlider, 2, DELAYAMOUNT_NAME);

    delayTimeSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DELAYTIME_ID, delayTimeSlider);
    setCustomSliderStyle(delayTimeSlider, 2, DELAYTIME_NAME);

    fadeinSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FADEIN_ID, fadeinSlider);
    setCustomSliderStyle(fadeinSlider, 2, FADEIN_NAME);

    fadeoutSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FADEOUT_ID, fadeoutSlider);
    setCustomSliderStyle(fadeoutSlider, 2, FADEOUT_NAME);

    rndIntervalSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, RND_INTERVAL_ID, rndIntervalSlider);
    setCustomSliderStyle(rndIntervalSlider, 2, RND_INTERVAL_NAME);

    rndDurationSliderValue = std::make_unique<AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, RND_DURATION_ID, rndDurationSlider);
    setCustomSliderStyle(rndDurationSlider, 2, RND_DURATION_NAME);

    // Creazione e configurazione dei bottoni
    gainButtonValue = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, GAIN_BTN_ID, gainButton);
    setCustomButtonStyle(gainButton, GAIN_BTN_NAME, GAIN_BTN_ID);
    gainSlider.setEnabled(gainButton.getToggleState());

    distButtonValue = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, DRIVE_BTN_ID, distButton);
    setCustomButtonStyle(distButton, DRIVE_BTN_NAME, DRIVE_BTN_ID);
    distSlider.setEnabled(distButton.getToggleState());

    crushButtonValue = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, BIT_BTN_ID, crushButton);
    setCustomButtonStyle(crushButton, BIT_BTN_NAME, BIT_BTN_ID);
    bitSlider.setEnabled(crushButton.getToggleState());

    downSampleButtonValue = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, DWNSMP_BTN_ID, downSampleButton);
    setCustomButtonStyle(downSampleButton, DWNSMP_BTN_NAME, DWNSMP_BTN_ID);
    downSampleSlider.setEnabled(downSampleButton.getToggleState());

    tailButtonValue = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, TAIL_BTN_ID, tailButton);
    setCustomButtonStyle(tailButton, TAIL_BTN_NAME, TAIL_BTN_ID);
    delayAmountSlider.setEnabled(tailButton.getToggleState());
    delayTimeSlider.setEnabled(tailButton.getToggleState());

    bypassButtonValue = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, BYPASS_BTN_ID, bypassButton);
    setCustomButtonStyle(bypassButton, BYPASS_BTN_NAME, BYPASS_BTN_ID);

    randomButtonValue = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, RANDOM_BTN_ID, randomButton);
    setCustomButtonStyle(randomButton, RANDOM_BTN_NAME, RANDOM_BTN_ID);
    rndIntervalSlider.setEnabled(randomButton.getToggleState());
    rndDurationSlider.setEnabled(randomButton.getToggleState());

    flutterButtonValue = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, FLUTTER_BTN_ID, flutterButton);
    setCustomButtonStyle(flutterButton, FLUTTER_BTN_NAME, FLUTTER_BTN_ID);

    reverseButtonValue = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, REV_BTN_ID, reverseButton);
    setCustomButtonStyle(reverseButton, REV_BTN_NAME, REV_BTN_ID);

    // Aggiungi i listener ai parametri, se necessario
    audioProcessor.treeState.addParameterListener(BIT_ID, this);
    audioProcessor.treeState.addParameterListener(DWNSMP_ID, this);
    audioProcessor.treeState.addParameterListener(DRYWET_ID, this);
    audioProcessor.treeState.addParameterListener(GAIN_BTN_ID, this);
    audioProcessor.treeState.addParameterListener(DRIVE_BTN_ID, this);
    audioProcessor.treeState.addParameterListener(BIT_BTN_ID, this);
    audioProcessor.treeState.addParameterListener(DWNSMP_BTN_ID, this);
    audioProcessor.treeState.addParameterListener(TAIL_BTN_ID, this);
    audioProcessor.treeState.addParameterListener(RANDOM_BTN_ID, this);

    setSize(1000, 600);
}

ANTARCTICAAudioProcessorEditor::~ANTARCTICAAudioProcessorEditor()
{
    audioProcessor.treeState.removeParameterListener(BIT_ID, this);
    audioProcessor.treeState.removeParameterListener(DWNSMP_ID, this);
    audioProcessor.treeState.removeParameterListener(DRYWET_ID, this);
    
    audioProcessor.treeState.removeParameterListener(GAIN_BTN_ID, this);
    audioProcessor.treeState.removeParameterListener(DRIVE_BTN_ID, this);
    audioProcessor.treeState.removeParameterListener(BIT_BTN_ID, this);
    audioProcessor.treeState.removeParameterListener(DWNSMP_BTN_ID, this);
}

void ANTARCTICAAudioProcessorEditor::parameterChanged(const juce::String& parameterID, float newValue)
{
    // buttons
    if (parameterID == GAIN_BTN_ID)
        gainSlider.setEnabled(gainButton.getToggleState());
    else if (parameterID == DRIVE_BTN_ID)
        distSlider.setEnabled(distButton.getToggleState());
    else if (parameterID == BIT_BTN_ID)
        bitSlider.setEnabled(crushButton.getToggleState());
    else if (parameterID == DWNSMP_BTN_ID)
        downSampleSlider.setEnabled(downSampleButton.getToggleState());
    else if (parameterID == TAIL_BTN_ID)
    {
        delayAmountSlider.setEnabled(tailButton.getToggleState());
        delayTimeSlider.setEnabled(tailButton.getToggleState());
    }
    else if (parameterID == RANDOM_BTN_ID)
    {
        rndIntervalSlider.setEnabled(randomButton.getToggleState());
        rndDurationSlider.setEnabled(randomButton.getToggleState());
    }
}

void ANTARCTICAAudioProcessorEditor::setCustomButtonStyle(Button& b, String name, String id)
{
    b.setName(name);
    b.setToggleState(audioProcessor.treeState.getRawParameterValue(id)->load(), NotificationType::dontSendNotification);
    addAndMakeVisible(&b);
}

void ANTARCTICAAudioProcessorEditor::setCustomSliderStyle(Slider& s, int type, String name)
{
    s.setName(name);
    
   if (type == 0) // means Rotary
       s.setSliderStyle(Slider::SliderStyle::Rotary);
    else if (type == 1) // Linear Vertical
        s.setSliderStyle(Slider::SliderStyle::LinearVertical);
    else if (type == 2) // Linear Horizontal
        s.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
    
    s.setSkewFactor(0.5);

    s.setTextBoxStyle(Slider::TextEntryBoxPosition::NoTextBox, true, 50, 20);
    addAndMakeVisible(&s);
}

//==============================================================================
void ANTARCTICAAudioProcessorEditor::paint (juce::Graphics& g)
{
    auto backgroundImage = ImageCache::getFromMemory (BinaryData::backgroundImg_jpg, BinaryData::backgroundImg_jpgSize);
    g.drawImage (backgroundImage, getLocalBounds().toFloat());
    
    g.setColour(Colours::black);
    
    int wText = 120;
    int hText = 20;
    
    
    
    auto drawTextSlider = [wText, hText, &g](Slider& s, int style) {
        if (style == 0) // means rotary
            g.drawText(s.getName(),
                   s.getX() + s.getWidth()/2 - wText/2,
                   s.getY() + s.getHeight() + 10,
                   wText,
                   hText,
                   Justification::centred);
        else if (style == 1) // means linear vertical
            g.drawText(s.getName(),
                       s.getX() + s.getWidth()/2 - wText/2,
                       s.getY() + s.getHeight() - hText/2 + 10,
                       wText,
                       hText,
                       Justification::centred);
        else if (style == 2) // means linear horizontal
            g.drawText(s.getName(),
                       s.getX() + s.getWidth(), // -30?
                       s.getY() + s.getHeight()/2 - hText/2,
                       wText,
                       hText,
                       Justification::centred);
    };
    
    // knobs
    drawTextSlider(gainSlider, 2);
    drawTextSlider(saturationSlider, 2);
    drawTextSlider(distSlider, 2);
    drawTextSlider(clipperSlider, 2);
    drawTextSlider(bitSlider, 2);
    drawTextSlider(downSampleSlider, 2);
    drawTextSlider(drywetSlider, 2);
    drawTextSlider(delayAmountSlider, 2);
    drawTextSlider(delayTimeSlider, 2);
    drawTextSlider(rndDurationSlider, 2);
    drawTextSlider(rndIntervalSlider, 2);
    
    // vertical sliders
    //drawTextSlider(inputSlider, 1);
    //drawTextSlider(outputSlider, 1);
    
    // buttons // to generalize
    auto drawTextButton = [wText, hText, &g](Button& b) {
        g.drawText(b.getName(),
                   b.getX() + b.getWidth(),
                   b.getY() + b.getHeight()/2 - hText/2,
                   wText,
                   hText,
                   Justification::centred);
    };
    
    // buttons
    drawTextButton(flutterButton);
    drawTextButton(reverseButton);
}

void ANTARCTICAAudioProcessorEditor::resized()
{
    // x, y, w, h
    
    int horizontalSliderWidth = 320;
    int horizontalSliderHeight = 50;
    int verticalSliderWidth = 50;
    int verticalSliderHeight = 160;
    
    int knobsDim = 120;
    int switcherDim = 25;
    
    int buttonLeftMargin = 50;
    int sliderLeftMargin = 100;
    int interComponentTextMargin = 100;
    int interComponentMargin = 30;
    
    // horizontal sliders
    gainSlider.setBounds(verticalSliderWidth+sliderLeftMargin, 0, horizontalSliderWidth, horizontalSliderHeight);
    saturationSlider.setBounds(verticalSliderWidth+sliderLeftMargin, horizontalSliderHeight*1, horizontalSliderWidth, horizontalSliderHeight);
    distSlider.setBounds(verticalSliderWidth+sliderLeftMargin, horizontalSliderHeight*2, horizontalSliderWidth, horizontalSliderHeight);
    clipperSlider.setBounds(verticalSliderWidth+sliderLeftMargin, horizontalSliderHeight*3, horizontalSliderWidth, horizontalSliderHeight);
    downSampleSlider.setBounds(verticalSliderWidth+sliderLeftMargin, horizontalSliderHeight*4, horizontalSliderWidth, horizontalSliderHeight);
    bitSlider.setBounds(verticalSliderWidth+sliderLeftMargin, horizontalSliderHeight*5, horizontalSliderWidth, horizontalSliderHeight);
    
    delayAmountSlider.setBounds(verticalSliderWidth+sliderLeftMargin, horizontalSliderHeight*6, horizontalSliderWidth, horizontalSliderHeight);
    delayTimeSlider.setBounds(verticalSliderWidth+sliderLeftMargin, horizontalSliderHeight*7, horizontalSliderWidth, horizontalSliderHeight);
    
    rndIntervalSlider.setBounds(verticalSliderWidth+sliderLeftMargin, horizontalSliderHeight*8, horizontalSliderWidth, horizontalSliderHeight);
    rndDurationSlider.setBounds(verticalSliderWidth+sliderLeftMargin, horizontalSliderHeight*9, horizontalSliderWidth, horizontalSliderHeight);

    drywetSlider.setBounds(verticalSliderWidth+sliderLeftMargin, horizontalSliderHeight*10, horizontalSliderWidth, horizontalSliderHeight);

    // left switchers
    gainButton.setBounds(gainSlider.getX()-switcherDim-interComponentMargin, gainSlider.getY()+switcherDim/2, switcherDim, switcherDim);
    
    distButton.setBounds(distSlider.getX()-switcherDim-interComponentMargin, distSlider.getY()+switcherDim/2, switcherDim, switcherDim);
    downSampleButton.setBounds(downSampleSlider.getX()-switcherDim-interComponentMargin, downSampleSlider.getY()+switcherDim/2, switcherDim, switcherDim);
    crushButton.setBounds(bitSlider.getX()-switcherDim-interComponentMargin, bitSlider.getY()+switcherDim/2, switcherDim, switcherDim);
    
    tailButton.setBounds(delayAmountSlider.getX()-switcherDim-interComponentMargin, (delayAmountSlider.getY()+delayTimeSlider.getY())/2+switcherDim/2, switcherDim, switcherDim); // between the two delay sliders
    randomButton.setBounds(rndIntervalSlider.getX()-switcherDim-interComponentMargin, (rndIntervalSlider.getY()+rndDurationSlider.getY())/2+switcherDim/2, switcherDim, switcherDim); // same
    
    // right switchers
    flutterButton.setBounds(delayAmountSlider.getX()+horizontalSliderWidth+interComponentMargin+interComponentTextMargin, tailButton.getY(), switcherDim, switcherDim);
    reverseButton.setBounds(delayAmountSlider.getX()+horizontalSliderWidth+interComponentMargin*2+switcherDim+interComponentTextMargin*2, tailButton.getY(), switcherDim, switcherDim);
    
    // only switchers section
    bypassButton.setBounds(verticalSliderWidth+buttonLeftMargin, 550, switcherDim, switcherDim);
    
    /*
    
    // vertical sliders
    inputSlider.setBounds(0, 0+knobsMargin, sliderWidth, sliderHeight-knobsMargin);
    outputSlider.setBounds(drywetSlider.getX()+knobsDim+knobsMargin, 0+knobsMargin, sliderWidth, sliderHeight-knobsMargin);
    
    */
}
