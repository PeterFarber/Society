#include <scpch.h>

#include "EventSystem.h"
#include "../Core/Events.h"

namespace Society {

	// EventSystem* EventSystem::m_instance{ nullptr };
	// std::mutex EventSystem::m_mutex;

	// EventSystem* EventSystem::GetInstance()
	// {
	// 	std::lock_guard<std::mutex> lock(m_mutex);
	// 	if (m_instance == nullptr)
	// 	{
	// 		m_instance = new EventSystem();
	// 	}
	// 	return m_instance;
	// }

	void EventSystem::AddObserver(Observer* observer)
	{
		m_observers.push_back(observer);
	}

	void EventSystem::RemoveObserver(Observer* observer)
	{
		m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), observer), m_observers.end());
	}

	void EventSystem::NotifyObservers(Event* event)
	{
		for (auto observer : m_observers)
		{
			std::vector<EVENT_TYPE> events = observer->GetEvents();
			if (std::find(events.begin(), events.end(), event->m_type) == events.end())
			{
				continue;
			}
			else {
				observer->OnNotify(event);

			}
		}
	}




}
