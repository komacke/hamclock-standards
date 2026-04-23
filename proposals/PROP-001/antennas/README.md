# Antenna Index

## Introduction

The Backend / HamClock api provides methods for fetching voacap propagation information in the following URLs:

> /ham/HamClock/fetchBandConditions.pl
> /ham/HamClock/fetchVOACAPArea.pl
> /ham/HamClock/fetchVOACAP-TOA.pl
> /ham/HamClock/fetchVOACAP-MUF.pl


Those functions take five optional arguments described herein

> &ANTDEINDEX=
> &ANTDXINDEX=
> &ANTDEDXCONTROL=
> &ANTDEAZ=
> &ANTDXAZ= 

## Compatibility

To provide information to the client, fetchBandCondictions.pl is also impacted to take an additional argument:

> &FORMAT=

Format=0 or absent indicates no special processing for compatibility is done. Existing processing and processing of the five optional arguments is performed.

For Format=1, the backend looks for any of the five arguments above and creates a csv table of: parametername,parametervaluereceived,parametervalueused.  This information can be used by the client to determine if a value such as antenna index is supported by the backend.



## Parameters


### ANTDEDXCONTROL

This argument controls what Antennas will be using for voacap propagation analysis. If missing, the value 0 isused

Values are specified as ANTDEDXCONTROL=control where control is processed as in the following table

| control | Description                        |
|---------|------------------------------------|
|    0    | process as default                 |
|    1    | Use ANTDEINDEX                     |
|    2    | Use ANTDXINDEX                     |
|    3    | Use both ANTDEINDEX and ANTDXINDEX |

### ANTDEINDEX, ANTDXINDEX
These parameters control what antenna profile is used for the DE and DX stations.

The value used is defined in the voacap.ant.csv file which is the specification of the interface. voacap antenna path is given; however,
the method used by the backend is implementation independent.
Instead of just showing the raw numeric value index, they are shown as msb and lsb values where the index is calculated as:
> index=msb*256+lsb

### ANTDEAZ, ANTDXAZ

These parameters set the antenna azimuth for the DE and DX locations respectively.

## Files

Files are described below

### voacap.ant.csv

The specificaiton of the antenna values used. The CSV has the following columns

| column | Description                                |
|--------|--------------------------------------------|
|   msb  | used in antenna index calculation          |
|   lsb  | used in antenna index calculation          |
| path   | path to antenna file under voacap antennas |
| description | description of antenna extracted from header of antenna file |

## README.md

This file

### gen_antenna_data.py

python program to generate antenna_data.py from voacap.ant.csv 
Intended for use on the backend server side.

usage:
```bash
python3 gen_antenna_data.py voacap.ant.csv antenna_data.py
```

### gen_antenna_data.sh

bash script to generate antenna_data.h from voacap.ant.csv
Intended for use on the HamClock client side.

usage:
```bash
./gen_antnna_data.sh voacap.ant.csv antenna_data.h 
```

### antenna_lookup.py

example code that provides lookup functions for antenna_data.py

### antenna_test.py

example code that shows usage of antenna_lookup.py

### antenna_test.cpp

example code that shows usage of antenna_lookup.py

### Makefile

Madefile that creates sample programs and generates header files
It can create programs antenna_dump to display antenna data, antenna_test to show usage similar to antenna_test.py

usage:
```bash
echo clean files
make clean
echo make all targets
make
echo run exmaple programs
./antenna_test
./antenna_dump
