# SimpleCursesGame

An ascii roguelike game engine that intends to implement an "Entity Component Framework" like the ones found in games like Caves of Qud.

## Entity Component Framework
To me, ECF is a way for different objects in a game to interact anonymously. Every game object represented in an ECF is made of components, which recieve events and interpret them in whatever way that they want. As you mix and match components, game objects have the potential to be more than the sum of their parts, while recycling the same components in different circumstances allows for code reusability and logically consistent game mechanics. I would compare it to the "Unix Philosophy". Things get complicated, though. When we send events, do we send them to the objects that contain the components, or to the components themselves? The order in which events are sent/recieved matters, since events can be altered before being passed on to different components.

## Purpose of This Project
I'm very inspired by the game Caves of Qud. In fact, according to Steam, I've played it for an embarrasing amount of hours. An issue with Qud is how it represents events with strings. Now, I could see how something like that makes things easier for the programmer. However, as much as C# is good with string handling (as Qud uses C#/Unity), doing things this way causes performance issues. Caves of Qud, a game which looks like [this](https://user-images.githubusercontent.com/21148680/179429845-7fd5d997-ead3-49e9-ae6a-f6d6b4ecc659.png) sometimes lags on my high-end gaming rig... Qud's co-creator, Brian Bucklew, [admits to this flaw](https://www.youtube.com/watch?v=U03XXzcThGU). Though the game is still in early access, it seems that the dev team has no intention of changing the fundamental qualities of a functioning game engine that has been in the works for over a decade (oh no, how dare they?!?). That's why I'm trying to design a system that doesn't rely on strings. Ideally, events should be able to contain arbitrary data, and have some sort of size limitation. Think network packets. Also, for the sake of optimization, I wanted to manage memory. C++ provides the ability to do this, while still having OOP concepts that are important for organizing code. Perhaps that's why the language is a standard of sorts for writing game engines (at least in the world of AAA). So far, the game uses ascii graphics, but I would love to implement real graphics using SDL. However, I'm not good at making sprites.

## Problems with This Project
I've identified some flaws with this engine. It's pretty good, but I'm going to rewrite it at some point. Memory safety is too complicated. Components should not be able to see each other, because it causes issues on deletion. Only Container Objects should be able to send/recieve events from the timeline, and only to/from other Container Objects. Again, this is to prevent issues on deletion. I need to set up a system for separating the engine code from the code that defines Component behavior. Events need to be like network packets, with header info and arbitrary data. Objects should look like trees, with Containers at the top and in the middle, with Components at the bottom.