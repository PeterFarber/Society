#ifndef SC_EVENTSYSTEM_H
#define SC_EVENTSYSTEM_H

#include <vector>
#include "Log.h"
#include "Interfaces/ISingleton.h"

namespace Society {

	class Observer;
	class Event;
	class EventSystem : public ISingleton<EventSystem>
	{
	private:

		std::vector<Observer*> m_observers;

	public:

		void AddObserver(Observer* observer);
		void RemoveObserver(Observer* observer);
		void NotifyObservers(Event* event);

	};

}

#endif
