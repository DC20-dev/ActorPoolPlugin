# ActorPoolPlugin

An Unreal Engine 5 plugin that provides an easy way to pool objects like bullets and similar.

## Installation

clone the repository in a folder (`ActorPoolPlugin` name is suggested) and put that inside Plugins folder in your project (if there isn't one create it), then restart the editor.

## Usage

First make sure that the plugin is enabled; you can do that by going to Edit/Plugins, and in the Plugins window search for `ActorPoolPlugin`: the plugin is enabled when the tick is checked!

The plugin exposes two main classes: `UActorPoolComponent` and `APoolableActor`.
These two classes can also be found in blueprints.

### `UActorPoolComponent`

This class is an actor component and can be attached to any actor.

It exposes two fields named `Actors Count` and `Actor Class`: the first one takes an integer number and it is used to specify the size of the pool, while the latter Requires an `APoolableActor` class reference, which will tell to the component what actors to use to poulate the pool.

_Note: These fields are avialable only in the class defaults (Blueprint), don't try to change them at runtime!_

To Initialize the pool you must call the `Init Pool` method and call it from the `Event BeginPlay` to actually populate and activate the pooling system.

### `APoolableActor`

This class is a child of `AActor` and implements all the required functionalities to work with the pool component.
To use it create a new Blueprint (or a class) and derive it from `APoolableActor` and then implement your logic as whatever the actor should do.

To then allow the bullets to return to their pool the `Reset` method (the one under Behaviour category) must be called; Remember to call it after every other reset logic your poolable actor has to run (ex. reset an explosion timer back to 0).

## Features

* `APoolableActor` automatically deactivates, hides itself and goes back to the pool: Super Easy!

* `APoolableActor` automatically destroys itself if the owning pool has been destroyed, ensuring that there is no garbage left around.

* Similarly, if the `APoolableActor` is active and running in game, it will ignore the destruction of the pool (unless differently specified) and will finish its lifetime before destroying itself.

* `UActorPoolComponent` automatically initializes the pool and manages the actors, both dead and alive in game, all you will need is to initialize and forget about it!
