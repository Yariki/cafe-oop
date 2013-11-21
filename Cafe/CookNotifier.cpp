///////////////////////////////////////////////////////////
//  CookNotifier.cpp
//  Implementation of the Class CookNotifier
//  Created on:      18-Nov-2013 12:26:29 AM
///////////////////////////////////////////////////////////

#include "CookNotifier.h"


CookNotifier::CookNotifier(){

}



CookNotifier::~CookNotifier(){

}

void CookNotifier::Attach(ICafeObserver<Cook>* observer){
	observer_ = observer;
}


void CookNotifier::Detach(ICafeObserver<Cook>* observer){
	observer_ = nullptr;
}


void CookNotifier::Notify(int command){
	if(!observer_)
		return;
}