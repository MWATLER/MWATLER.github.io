//iComponent.h - interface class declaration for a generic component
//
// 16-Mar-21  M. Watler         Created.

#ifndef _ICOMPONENT_H_
#define _ICOMPONENT_H_

class iComponent {
	//no variables
public:
	virtual void SetCurrent(double) = 0;//a pure virtual function
	virtual void PrintReport() = 0;//a pure virtual function
};

iComponent* CreateComponent();

#endif//_ICOMPONENT_H_