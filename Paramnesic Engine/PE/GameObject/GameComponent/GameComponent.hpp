#pragma once

namespace pe
{
	class GameObject;

	class GameComponent
	{
	protected:
		GameComponent(pe::GameObject& object, bool multiplicable);
		virtual ~GameComponent() = 0;

		const bool& isMultiplicable() const;

		virtual void tick();

		friend class GameObject;

	protected:
		pe::GameObject& m_object;

	private:
		bool m_multiplicable;
	};
}