/**
 * @file Machine1Factory.cpp
 * @author Charles Owen
 */

#include "pch.h"
#include "Machine1Factory.h"
#include "Machine.h"
#include "Shape.h"
#include "Motor.h"
#include "Pulley.h"
#include "PegWheel.h"
#include "Peg.h"
//#include "Lever.h"
//#include "Instrument.h"

/// The images directory in resources
const std::wstring ImagesDirectory = L"/images";

/// The audio directory in resources
const std::wstring AudioDirectory = L"/audio";

/**
 * Constructor
 * @param resourcesDir Path to the resources directory
 * @param audioEngine The miniaudio engine
 */
Machine1Factory::Machine1Factory(std::wstring resourcesDir, ma_engine* audioEngine) :
        mResourcesDir(resourcesDir), mAudioEngine(audioEngine)
{
    mImagesDir = mResourcesDir + ImagesDirectory;
    mAudioDir = mResourcesDir + AudioDirectory;
}

/**
 * Factory method to create machine #1
 * @return
 */
std::shared_ptr<Machine> Machine1Factory::Create()
{

// The machine itself
    // In this solution the machine number is passed
    // to the working machine constructor, so it knows
    // its number.
    auto machine = std::make_shared<Machine>(1);

    // The framework. This is a basic shape.
    auto base = std::make_shared<Shape>();
    int wid = 543;
    int hit = 366;
    base->Rectangle(-wid/2, 0, wid, hit);
    base->SetImage(mImagesDir + L"/framework.png");
    machine->AddComponent(base);

    // The motor
    auto motor = std::make_shared<Motor>(mImagesDir);
    motor->SetPosition(-222, -48);
    // Make the motor rotate counter-clockwise at 0.2
    // revolutions per second. Negative means counter-clockwise
    motor->SetRotationSpeed(-0.2);
    machine->AddComponent(motor);

    // The pulley driven by the motor
    auto pulley1 = std::make_shared<Pulley>(30);
    pulley1->SetImage(mImagesDir + L"/pulley2.png");
    pulley1->SetPosition(motor->GetX(), motor->GetY() - 50);

    // Connect the motor as a source to the pulley as a sink
    motor->GetSource()->AddSink(pulley1->GetSink());

//    //
//    // The instruments
//    //
//    auto kick = std::make_shared<Instrument>(mImagesDir + L"/drum.png",
//            mAudioDir + L"/kick.wav",
//            mAudioEngine);
//    kick->CenteredSquare(100);
//    kick->SetPosition(-142, -310);
//    machine->AddComponent(kick);
//
//    auto tom = std::make_shared<Instrument>(mImagesDir + L"/drum.png",
//            mAudioDir + L"/tom.wav",
//            mAudioEngine);
//    tom->CenteredSquare(60);
//    tom->SetPosition(-55, -305);
//    machine->AddComponent(tom);
//
//    auto snare = std::make_shared<Instrument>(mImagesDir + L"/drum.png",
//            mAudioDir + L"/snare.wav",
//            mAudioEngine);
//    snare->CenteredSquare(50);
//    snare->SetPosition(25, -305);
//    machine->AddComponent(snare);
//
//    auto cowbell = std::make_shared<Instrument>(mImagesDir + L"/cowbell.png",
//            mAudioDir + L"/cowbell.wav",
//            mAudioEngine);
//    cowbell->CenteredSquare(60);
//    cowbell->SetPosition(105, -315);
//    machine->AddComponent(cowbell);
//
//    auto cymbal = std::make_shared<Instrument>(mImagesDir + L"/cymbal.png",
//            mAudioDir + L"/cymbal.wav",
//            mAudioEngine);
//    cymbal->CenteredSquare(80);
//    cymbal->SetPosition(188, -325);
//    machine->AddComponent(cymbal);

    // Define standard locations for the pulleys, peg wheels, and levers
    const int PulleyY = -164;
    int pulleyX = -115;             // For the first pulley
    const int IdlerY = -84;
    int idlerX = -80;               // For the first idler
    const int PulleySpacing = 80;   // How far the pulleys are apart
    const int LeverY = -229;        // Y location for a level

//    /// Structure used to store data for the
//    /// five different drum systems (columns)
//    struct DrumData {
//        /// The instrument for this one
//        std::shared_ptr<Instrument> mInstrument;
//
//        /// The peg locations for each of the peg wheels
//        /// To make the music easier to determine, these
//        /// are divided by 16 so instead of turns we have
//        /// 16 positions around the peg wheel.
//        std::vector<double> mPegLocations;
//
//        /// Radius of the pulley that drives the peg wheel
//        double mPulleyRadius;
//
//        /// Constant amount added to the peg wheel rotation
//        /// to ensure the drums are synced to each other
//        double mPegWheelPhase;
//    };
//
//    /// The actual drum data
//    const DrumData drumData[5] = {
//            {kick, {0, 8}, 10, 0.05},                       // Kick drum
//            {tom, {1, 3, 5, 7, 9, 11, 13, 15}, 20, 0.01},   // Tom
//            {snare, {2, 6, 10, 14}, 20, 0.01},              // Snare
//            {cowbell, {0, 4, 8, 12}, 10, 0.05},             // More cowbell!
//            {cymbal, {8}, 20, 0.01}                         // Cymbal
//    };

    // Used to keep track of hte last drum pulley added
    std::shared_ptr<Pulley> lastDrumPulley = pulley1;

    auto pulley_t = std::make_shared<Pulley>(10);
    pulley_t->SetImage(mImagesDir + L"/pulley2.png");
    pulley_t->SetPosition(pulleyX, PulleyY);
    pulley1->Drive(pulley_t);

    auto pegWheel = std::make_shared<PegWheel>(mImagesDir);
    pegWheel->SetPosition(pulleyX, PulleyY);
    pulley_t->GetSource()->AddSink(pegWheel->GetSink());


    auto temp = {1, 3, 5, 7, 9, 11, 13, 15};
        for(double location : temp)
        {
            pegWheel->AddPeg(location / 16.0);
        }

    machine->AddComponent(pegWheel);
    machine->AddComponent(pulley_t);

//
//    for(int i=0; i<5; i++)
//    {
//        // Data for this pulley/drum
//        auto& drumDatum = drumData[i];
//
//        //
//        // The peg wheel
//        //
//        auto pegWheel = std::make_shared<PegWheel>(mImagesDir);
//        pegWheel->SetPosition(pulleyX, PulleyY);
//        machine->AddComponent(pegWheel);
//
//        // Add the pegs
//        for(double location : drumDatum.mPegLocations)
//        {
//            pegWheel->AddPeg(location / 16.0);
//        }
//
//        //
//        // The pulley that drives the peg wheel
//        //
//        auto drumPulley = std::make_shared<Pulley>(drumDatum.mPulleyRadius);
//        drumPulley->SetImage(mImagesDir + L"/pulley1.png");
//        drumPulley->SetPosition(pulleyX, PulleyY);
//        machine->AddComponent(drumPulley);
//
//        // Keep track of the last drum pulley
//        lastDrumPulley = drumPulley;
//
//        // This indicates that drumPulley is being driven by
//        // pulley1, which is the source of power to the belt.
//        pulley1->Drive(drumPulley);
//
//        // Connect the drum pulley to the peg wheel
//        drumPulley->GetSource()->AddSink(pegWheel->GetSink());
//        pegWheel->GetSink()->SetPhase(drumDatum.mPegWheelPhase);
//
//        //
//        // The lever that the peg wheel trips
//        //
//        auto lever = std::make_shared<Lever>(mImagesDir);
//        lever->SetPosition(pulleyX, LeverY);
//        machine->AddComponent(lever);
//        pegWheel->AddLever(lever);
//
//        //
//        // The drumstick
//        //
//        auto stick = std::make_shared<Shape>();
//        stick->Rectangle(-2, 2, 5, 80);
//        stick->SetPosition(pulleyX, LeverY);
//        stick->SetImage(mImagesDir + L"/drumstick.png");
//        machine->AddComponent(stick);
//
//        lever->GetSource()->AddSink(stick->GetSink());
//        stick->GetSink()->SetPhase(-0.02);
//
//        // Connect the lever (source of strikes) to the instrument
//        lever->SetStruckComponent(drumDatum.mInstrument);
//
//        //
//        // Idler pulleys between the peg wheel pulleys
//        //
//        if(i < 4)
//        {
//            auto drumIdler = std::make_shared<Pulley>(15);
//            drumIdler->SetImage(mImagesDir + L"/idler1s.png");
//            drumIdler->SetPosition(idlerX, IdlerY);
//            machine->AddComponent(drumIdler);
//
//            // This indicates that drumIdler is being driven
//            // by pulley1 and that the back of the belt is
//            // passing over the pulley.
//            pulley1->Drive(drumIdler, true);
//        }
//
//        pulleyX += PulleySpacing;
//        idlerX += PulleySpacing;
//    }

    // Bottom right pulley
    auto pulley2 = std::make_shared<Pulley>(20);
    pulley2->SetImage(mImagesDir + L"/pulley1.png");
    pulley2->SetPosition(200, -32);
    machine->AddComponent(pulley2);
    pulley1->Drive(pulley2);

    // Bottom left pulley
    auto pulley3 = std::make_shared<Pulley>(20);
    pulley3->SetImage(mImagesDir + L"/pulley1.png");
    pulley3->SetPosition(-150, -32);
    machine->AddComponent(pulley3);
    pulley1->Drive(pulley3);

    // The order we add to the machine determines the drawing order.
    // This ensures the serpentine belt is drawn after the pulleys
    // and peg wheels to ensure it's on the top.
    machine->AddComponent(pulley1);

    //
    // Pulley to drive the pulley that holds the flag
    //
    auto pulley4 = std::make_shared<Pulley>(15);
    pulley4->SetImage(mImagesDir + L"/pulley3.png");
    pulley4->SetPosition(lastDrumPulley->GetX(), lastDrumPulley->GetY());
    lastDrumPulley->GetSource()->AddSink(pulley4->GetSink());
    machine->AddComponent(pulley4);

    // Idler to move the pulley belt over
    auto idler1 = std::make_shared<Pulley>(10);
    idler1->SetImage(mImagesDir + L"/idler1.png");
    idler1->SetPosition(232, -200);
    machine->AddComponent(idler1);
    pulley4->Drive(idler1, true);

    // Pulley that drive the flag
    auto pulley5 = std::make_shared<Pulley>(15);
    pulley5->SetImage(mImagesDir + L"/pulley3.png");
    pulley5->SetPosition(248, -352);
    machine->AddComponent(pulley5);
    pulley4->Drive(pulley5);

    // Other idler
    auto idler2 = std::make_shared<Pulley>(10);
    idler2->SetImage(mImagesDir + L"/idler1.png");
    idler2->SetPosition(248, PulleyY);
    machine->AddComponent(idler2);
    pulley4->Drive(idler2);

    // The rotating flag
    auto flag = std::make_shared<Shape>();
    flag->SetImage(mImagesDir + L"/msu-flag.png");
    flag->Rectangle(0, 0, 28, 60);
    flag->SetPosition(pulley5->GetX(), pulley5->GetY());
    machine->AddComponent(flag);
    pulley5->GetSource()->AddSink(flag->GetSink());

    return machine;







//    // The machine itself
//    // In this solution the machine number is passed
//    // to the working machine constructor, so it knows
//    // its number.
//    auto machine = std::make_shared<Machine>(1);
//
//    // The framework. This is a basic shape.
//    auto base = std::make_shared<Shape>();
//    int wid = 543;
//    int hit = 366;
//    base->Rectangle(-wid/2, 0, wid, hit);
//    base->SetImage(mImagesDir + L"/framework.png");
//    machine->AddComponent(base);
//
//    // The motor
//    auto motor = std::make_shared<Motor>(mImagesDir);
//    motor->SetPosition(-222, -95);
//    // Make the motor rotate counter-clockwise at 0.2
//    // revolutions per second. Negative means counter-clockwise
//    motor->SetRotationSpeed(-0.2);
//    machine->AddComponent(motor);
//
//    // The pulley driven by the motor
//    auto pulley1 = std::make_shared<Pulley>(30);
//    pulley1->SetImage(mImagesDir + L"/pulley2.png");
//    pulley1->SetPosition(motor->GetX(), motor->GetY());
//    machine->AddComponent(pulley1);
//
//    // Connect the motor as a source to the pulley as a sink
//    motor->GetSource()->AddSink(pulley1->GetSink());
//
//
//    // Define standard locations for the pulleys, peg wheels, and levers
//    const int PulleyY = -164;
//    int pulleyX = -115;             // For the first pulley
//    const int IdlerY = -84;
//    int idlerX = -80;               // For the first idler
//    const int PulleySpacing = 80;   // How far the pulleys are apart
//    const int LeverY = -229;        // Y location for a level
//
//    // Bottom right pulley
//    auto pulley2 = std::make_shared<Pulley>(20);
//    pulley2->SetImage(mImagesDir + L"/pulley1.png");
//    pulley2->SetPosition(200, -32);
//    machine->AddComponent(pulley2);
//    pulley1->Drive(pulley2);
//
//    // Bottom left pulley
//    auto pulley3 = std::make_shared<Pulley>(20);
//    pulley3->SetImage(mImagesDir + L"/pulley1.png");
//    pulley3->SetPosition(-150, -32);
//    machine->AddComponent(pulley3);
//    pulley1->Drive(pulley3);
//
//    // The order we add to the machine determines the drawing order.
//    // This ensures the serpentine belt is drawn after the pulleys
//    // and peg wheels to ensure it's on the top.
//
//    //
//    // Pulley to drive the pulley that holds the flag
//    //
//
//    // Used to keep track of hte last drum pulley added
//    std::shared_ptr<Pulley> lastDrumPulley = pulley3;
//
//    auto pulley4 = std::make_shared<Pulley>(15);
//    pulley4->SetImage(mImagesDir + L"/pulley3.png");
//    pulley4->SetPosition(lastDrumPulley->GetX(), lastDrumPulley->GetY());
//    lastDrumPulley->GetSource()->AddSink(pulley4->GetSink());
//    machine->AddComponent(pulley4);
//
//    // Idler to move the pulley belt over
//    auto idler1 = std::make_shared<Pulley>(10);
//    idler1->SetImage(mImagesDir + L"/idler1.png");
//    idler1->SetPosition(232, -200);
//    machine->AddComponent(idler1);
//    pulley4->Drive(idler1, true);
//
//    // Pulley that drive the flag
//    auto pulley5 = std::make_shared<Pulley>(15);
//    pulley5->SetImage(mImagesDir + L"/pulley3.png");
//    pulley5->SetPosition(248, -352);
//    machine->AddComponent(pulley5);
//    pulley4->Drive(pulley5);
//
//    // Other idler
//    auto idler2 = std::make_shared<Pulley>(10);
//    idler2->SetImage(mImagesDir + L"/idler1.png");
//    idler2->SetPosition(248, PulleyY);
//    machine->AddComponent(idler2);
//    pulley4->Drive(idler2);
//
//    // The rotating flag
//    auto flag = std::make_shared<Shape>();
//    flag->SetImage(mImagesDir + L"/msu-flag.png");
//    flag->Rectangle(0, 0, 28, 60);
//    flag->SetPosition(pulley5->GetX(), pulley5->GetY());
//    machine->AddComponent(flag);
//    pulley5->GetSource()->AddSink(flag->GetSink());
//    return machine;

}