TruckMaker 14.0 Project: Differential Engagement and Disengagement

This document outlines the steps and conditions required to engage and disengage the differential between the 6x4 and 6x2 modes in a TruckMaker 14.0 project. It also covers the necessary road scenario setup in the Scenario Editor for testing and validation.

Requirements
1. Building the Off-Road Road Scenario
	In the Scenario Editor, create an off-road scenario with the following characteristics:
	Road Surface: Set to "Mud Road".
	Terrain: Add a tree and an elevation profile to simulate a realistic off-road environment.

2. Engaging and Disengaging the Differential (6x4 and 6x2 Modes)
	The Volvo Truck is configured to engage and disengage between 6x4 and 6x2 modes under the following conditions.

Conditions for Engagement
	To switch to 6x4 mode, the following conditions must be met:
	Vehicle Speed: Below 2 km/h.
	Accelerator Pedal Position / Engine RPM: Above 1000 RPM.
	R1 & R2 Axle Input Shaft RPM Difference: Must be greater than 60 RPM.
	R1 (LH + RH) & R2 (LH + RH) RPM Difference: Must be greater than 20 RPM.

Synchronization for Engagement
	Engine Torque Cutoff: Apply for 5 seconds.
	Braking Application on R1 or R2 Complete Axle: Must meet the RPM difference of above 20 for proper synchronization.

Conditions for Disengagement
To switch to 6x2 mode, the following conditions must be met:

	Vehicle Speed: Above 20 km/h.
	Engine Torque Limitation: Limit to 10 kgm for 2 seconds.

Regular Expression Validation
The truck's engagement and disengagement between 6x4 and 6x2 are verified using the following conditions, checked via Regular Expressions. If the conditions are satisfied, the truck will shift between the two modes.

UAQ for Differential Engagement:
The UAQ (User-Defined Parameter Query) used for this process is "PT.Gen.DL.CDiffR.TrqRatio".