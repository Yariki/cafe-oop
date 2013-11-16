///////////////////////////////////////////////////////////
//  ICafeObserver.h
//  Implementation of the Class ICafeObserver
//  Created on:      16-Nov-2013 9:31:13 PM
//  Original author: Yariki
///////////////////////////////////////////////////////////

#if !defined(EA_E09B53EE_F614_48a1_84CD_77ED6EE8EA57__INCLUDED_)
#define EA_E09B53EE_F614_48a1_84CD_77ED6EE8EA57__INCLUDED_

template<class T>
class ICafeObserver
{

public:
	ICafeObserver(Cafe* cafe) {cafe_ = cafe}
	virtual ~ICafeObserver() {}
	virtual void Update(int command, T* obj) = 0;

protected:
	Cafe* cafe_;

};
#endif // !defined(EA_E09B53EE_F614_48a1_84CD_77ED6EE8EA57__INCLUDED_)
