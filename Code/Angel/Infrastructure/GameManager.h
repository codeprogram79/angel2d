#pragma once

#include "../Actors/Actor.h"
#include "../Messaging/Message.h"
#include "../Infrastructure/SoundDevice.h"

// forward declarations
class b2Shape;

///A class to oversee the high-level aspects of your game
/** 
 * Oftentimes you want to have a central class that handles game-flow. Things 
 *  like keeping score, managing the creation of new Actors, etc. You could
 *  do this with a centralized Actor that doesn't get drawn, but there's a lot
 *  of functionality (baggage) on the Actor class that you wouldn't be using 
 *  in that case. 
 * 
 * The GameManager class is a Renderable, so it will get all the Render and
 *  Update calls that an Actor would receive. You register it with your World 
 *  (via the \c theWorld.SetGameManager function) and can then retrieve it 
 *  from anywhere in your game. 
 */
class GameManager : public Renderable, public MessageListener
{
public:
	/**
	 * The default constructor is empty; we expect you to subclass to do 
	 *  anything meaningful. 
	 */
	GameManager(){}
	
	/**
	 * The destructor is also empty. 
	 */
	~GameManager(){}

	/**
	 * Override of the Renderable::Render function. Doesn't do anything in 
	 *  this base class. 
	 */
	virtual void Render();
	
	/**
	 * Override of the Renderable::Update function. Also doesn't do anything 
	 *  in the base class, but in the future it might, so make sure you call 
	 *  this in any override implementations. 
	 * 
	 * @param dt The amount of time elapsed since the start of the last frame. 
	 */
	virtual void Update(float dt);
	
	/**
	 * In your GameManager, you can define a custom function to determine whether
	 *  specific Renderables should be protected from the World::UnloadAll 
	 *  function. This function will get called for each Renderable during
	 *  an UnloadAll attempt. 
	 * 
	 * @param renderable The Renderable to test
	 * @return Whether it should be protected (returning false means it will
	 *   be removed from the world)
	 */
	virtual bool IsProtectedFromUnloadAll( Renderable* renderable ) {return false;} 
	
	/**
	 * Override of the MessageListener::ReceiveMessage function. Does nothing
	 *  in this base class. 
	 * 
	 * @param message The received message. 
	 */
	virtual void ReceiveMessage(Message* message) {}
	
	/**
	 * The sound system needs a callback that gets triggered when any sound
	 *  ends. Since the GameManager is a logical place to have sound control
	 *  functionality, it has this function for you to implement. 
	 * 
	 * @param sound The handle to the sound that has just completed. 
	 */
	virtual void SoundEnded(SOUND_HANDLE sound){}
};
