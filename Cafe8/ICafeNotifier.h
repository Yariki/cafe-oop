///////////////////////////////////////////////////////////
//  ICafeNotifier.h
//  Implementation of the Interface ICafeNotifier
//  Created on:      18-Nov-2013 12:13:49 AM
///////////////////////////////////////////////////////////

#if !defined(EA_CC92D396_196C_437f_A687_7A9D305AC278__INCLUDED_)
#define EA_CC92D396_196C_437f_A687_7A9D305AC278__INCLUDED_

template<class T>
class ICafeNotifier
{

public:
	ICafeNotifier() {

	}

	virtual ~ICafeNotifier() {

	}
	
	virtual void Attach(T* observer) { observer_ = observer; }
	virtual void Detach(T* observer)  { observer_ = nullptr;};
	virtual void Notify(int command) =0;
	virtual T* getObserver() {return observer_;}

protected:
	T* observer_;
};
#endif // !defined(EA_CC92D396_196C_437f_A687_7A9D305AC278__INCLUDED_)
