EESchema Schematic File Version 2  date Thu 06 Dec 2012 04:12:20 PM CST
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:special
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:TXB0108
EELAYER 43  0
EELAYER END
$Descr A4 11700 8267
encoding utf-8
Sheet 1 1
Title ""
Date "6 dec 2012"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	5300 4600 5300 3150
Wire Wire Line
	5300 3150 4750 3150
Wire Wire Line
	4750 3050 4750 3150
Wire Wire Line
	4750 3050 4400 3050
Connection ~ 5650 2900
Wire Wire Line
	5650 2900 5650 4250
Wire Wire Line
	5650 4250 6250 4250
Wire Wire Line
	6250 4250 6250 4150
Connection ~ 4650 3050
Wire Wire Line
	4400 3050 4400 3250
Wire Wire Line
	4750 4150 4400 4150
Wire Wire Line
	4750 3950 4400 3950
Wire Wire Line
	4750 3750 4400 3750
Wire Wire Line
	4750 3550 4400 3550
Wire Wire Line
	4400 3350 4550 3350
Wire Wire Line
	4550 3350 4550 3250
Wire Wire Line
	4550 3250 4750 3250
Wire Wire Line
	6350 2900 6350 3350
Wire Wire Line
	6350 3350 6250 3350
Wire Wire Line
	6250 4050 6550 4050
Wire Wire Line
	6250 3850 6550 3850
Wire Wire Line
	6250 3650 6550 3650
Wire Wire Line
	6250 3450 6550 3450
Wire Wire Line
	6250 3250 6450 3250
Wire Wire Line
	6450 3250 6450 3350
Wire Wire Line
	6450 3350 6550 3350
Wire Wire Line
	6250 3550 6550 3550
Wire Wire Line
	6250 3750 6550 3750
Wire Wire Line
	6250 3950 6550 3950
Wire Wire Line
	6250 4150 6550 4150
Wire Wire Line
	6550 3250 6550 3050
Wire Wire Line
	6550 3050 6350 3050
Connection ~ 6350 3050
Wire Wire Line
	4750 3450 4400 3450
Wire Wire Line
	4750 3650 4400 3650
Wire Wire Line
	4750 3850 4400 3850
Wire Wire Line
	4750 4050 4400 4050
Wire Wire Line
	4750 3350 4650 3350
Wire Wire Line
	4650 3350 4650 2900
Wire Wire Line
	5050 2900 5950 2900
Wire Wire Line
	4650 4150 4650 4600
Wire Wire Line
	4650 4600 4800 4600
Connection ~ 4650 4150
$Comp
L R R1
U 1 1 50C11694
P 5050 4600
F 0 "R1" V 5130 4600 50  0000 C CNN
F 1 "10k" V 5050 4600 50  0000 C CNN
	1    5050 4600
	0    1    1    0   
$EndComp
$Comp
L C C1
U 1 1 50C1168F
P 4850 2900
F 0 "C1" H 4900 3000 50  0000 L CNN
F 1 "0.1uf" H 4900 2800 50  0000 L CNN
	1    4850 2900
	0    -1   -1   0   
$EndComp
$Comp
L C C2
U 1 1 50C11685
P 6150 2900
F 0 "C2" H 6200 3000 50  0000 L CNN
F 1 "0.1uf" H 6200 2800 50  0000 L CNN
	1    6150 2900
	0    1    1    0   
$EndComp
$Comp
L CONN_10 P1
U 1 1 50C11659
P 4050 3700
F 0 "P1" V 4000 3700 60  0000 C CNN
F 1 "CONN_10" V 4100 3700 60  0000 C CNN
	1    4050 3700
	-1   0    0    -1  
$EndComp
$Comp
L CONN_10 P2
U 1 1 50C1163D
P 6900 3700
F 0 "P2" V 6850 3700 60  0000 C CNN
F 1 "CONN_10" V 6950 3700 60  0000 C CNN
	1    6900 3700
	1    0    0    1   
$EndComp
$Comp
L TXB0108 U1
U 1 1 50C11632
P 5500 3700
F 0 "U1" H 5500 3600 50  0000 C CNN
F 1 "TXB0108" H 5500 3800 50  0000 C CNN
F 2 "MODULE" H 5500 3700 50  0001 C CNN
F 3 "DOCUMENTATION" H 5500 3700 50  0001 C CNN
	1    5500 3700
	1    0    0    -1  
$EndComp
$EndSCHEMATC
