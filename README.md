# CRC Generator

The code implement a CRC generator from CRC-1 to CRC-8, for any polynomial.

## Introduction
A cyclic redundancy check (CRC) is an error detection code used to detect accidental changes to raw data.
Data blocks entering these systems are assigned a short check value, based on the remainder of a polynomial division of their contents.
On retrieval, the calculation is repeated in order to check if the two values coincide.

## The Code
The code is made in such a way that defining three constants is able to generate the CRC of the desired dimension (from 1 to 8) and polynomial.

* PLY is set with the desired polionomial.
* CRC_DIM is the size of the CRC we want to generate.
* INIT is the initial value to be set to the residual.

Ex. :
For the CRC-5-USB
```
PLY = 0x05    <-- x^5 + x^2 + 1  (100101 but the first 1 is not considered --> 101 = 0x05)
CRC_DIM = 5   <-- CRC-5
INIT = 0x00
```

### Inputs
The function inputs are two:
* The message on which to perform the polynomial additions.
* Size of the message expressed in bytes.

In particular, the message must be passed in the form of a byte array (char message [N]) then through a pointer, so the size will be the number of "cells" of the array (sizeof (message)).

#### Output 
The function return is an unsigned char that represents the residual, the CRC.
