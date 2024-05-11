#ifndef SC_EVENTS_H
#define SC_EVENTS_H

#include <vector>
#include "Log.h"
#include "EventSystem.h"

namespace Society {

	enum EVENT_TYPE
	{
		// Window Events
		WINDOW_CLOSE,
		WINDOW_RESIZE,
		WINDOW_FOCUS,
		WINDOW_ICONIFY,
		WINDOW_MAXIMIZE,
		WINDOW_CONTENT_SCALE,
		WINDOW_POS,
		WINDOW_REFRESH,
		// App Events
		APP_TICK,
		APP_UPDATE,
		APP_RENDER,
		// Key Events
		KEY_PRESSED,
		KEY_RELEASED,
		KEY_REPEATED,
		KEY_TYPED,
		// Mouse Events
		MOUSE_BUTTON_PRESSED,
		MOUSE_BUTTON_RELEASED,
		MOUSE_MOVED,
		MOUSE_SCROLLED
	};

	class Event
	{
	public:
		/* data */
		EVENT_TYPE m_type;
	public:
		Event(EVENT_TYPE type) : m_type(type) {}
		virtual ~Event() {}

		virtual void Print() {
			SC_CORE_INFO("Event Type: {0}", static_cast<int>(m_type));
		}
	};

	class KeyEvent : public Event
	{
	public:
		/* data */
		int m_keyCode;
		int m_scanCode;
		int m_action;
		int m_mods;
	public:
		KeyEvent(EVENT_TYPE type, int keyCode, int scanCode, int action, int mods) : Event(type), m_keyCode(keyCode), m_scanCode(scanCode), m_action(action), m_mods(mods) {}
		~KeyEvent() {}

		void Print() {
			Event::Print();

			SC_CORE_INFO("Key: {0}, Scancode: {1}, Action: {2}, Mods: {3}", m_keyCode, m_scanCode, m_action, m_mods);
		}

	};

	class MouseEvent : public Event
	{
	public:
		/* data */
		int m_button;
		int m_action;
		int m_mods;
	public:
		MouseEvent(EVENT_TYPE type, int button, int action, int mods) : Event(type), m_button(button), m_action(action), m_mods(mods) {}
		~MouseEvent() {}

		void Print() {
			Event::Print();

			SC_CORE_INFO("Button: {0}, Action: {1}, Mods: {2}", m_button, m_action, m_mods);
		}
	};

	class WindowEvent : public Event
	{
	public:
		/* data */
		int m_width;
		int m_height;
		int m_xscale;
		int m_yscale;
		int m_xpos;
		int m_ypos;
		int m_iconified;
		int m_maximized;
		int m_focused;
	public:

		WindowEvent(EVENT_TYPE type, int width, int height, int xscale, int yscale, int xpos, int ypos, int iconified, int maximized, int focused) : Event(type), m_width(width), m_height(height), m_xscale(xscale), m_yscale(yscale), m_xpos(xpos), m_ypos(ypos), m_iconified(iconified), m_maximized(maximized), m_focused(focused) {}
		~WindowEvent() {}

		void Print() {
			Event::Print();

			switch (m_type) {
			case EVENT_TYPE::WINDOW_RESIZE:
				SC_CORE_INFO("Window Resize: {0}, {1}", m_width, m_height);
				break;
			case EVENT_TYPE::WINDOW_CONTENT_SCALE:
				SC_CORE_INFO("Window content scale: {0}, {1}", m_xscale, m_yscale);
				break;
			case EVENT_TYPE::WINDOW_POS:
				SC_CORE_INFO("Window position: {0}, {1}", m_xpos, m_ypos);
				break;
			case EVENT_TYPE::WINDOW_ICONIFY:
				SC_CORE_INFO("Window iconify: {0}", m_iconified);
				break;
			case EVENT_TYPE::WINDOW_MAXIMIZE:
				SC_CORE_INFO("Window maximize: {0}", m_maximized);
				break;
			case EVENT_TYPE::WINDOW_FOCUS:
				SC_CORE_INFO("Window focus: {0}", m_focused);
				break;
			case EVENT_TYPE::WINDOW_CLOSE:
				SC_CORE_INFO("Window close");
				break;
			case EVENT_TYPE::WINDOW_REFRESH:
				SC_CORE_INFO("Window refresh");
				break;
			default:
				break;
			}
		}
	};

	class Observer
	{
	private:
		/* data */
		std::vector<EVENT_TYPE> m_events;
	public:
		virtual ~Observer() = 0;

		std::vector<EVENT_TYPE> GetEvents() { return m_events; }

		void ListenFor();

		template<typename First, typename ... Events>
		void ListenFor(First arg, const Events&... rest) {
			m_events.push_back(arg);
			EventSystem::GetInstance()->AddObserver(this);
			ListenFor(rest...);
		}


		virtual void OnNotify(Event* event) = 0;

	};




}

#endif  // !SC_EVENTS_H
