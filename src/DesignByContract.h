//
// Created by othma on 22/03/2022.
//

#ifndef UNTITLED_DESIGNBYCONTRACT_H
#define UNTITLED_DESIGNBYCONTRACT_H
//============================================================================
// Name        : DesignByContract.h
// Author      : Serge Demeyer
// Version     :
// Copyright   : Project Software Engineering - BA1 Informatica - Serge Demeyer - University of Antwerp
// Description : Declarations for design by contract in C++
//============================================================================

#include <cassert>

#define REQUIRE(assertion, what) \
	if (!(assertion)) __assert (what, __FILE__, __LINE__)

#define ENSURE(assertion, what) \
	if (!(assertion)) __assert (what, __FILE__, __LINE__)


#endif //UNTITLED_DESIGNBYCONTRACT_H
