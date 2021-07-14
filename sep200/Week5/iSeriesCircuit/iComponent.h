//iComponent.h - interface class declaration for a generic component
//
// 16-Mar-21  M. Watler         Created.

#ifndef _ICOMPONENT_H_
#define _ICOMPONENT_H_

class iComponent {
public:
	virtual void SetCurrent(double) = 0;
	virtual void PrintReport() = 0;
};

iComponent* CreateComponent();

#endif//_ICOMPONENT_H_