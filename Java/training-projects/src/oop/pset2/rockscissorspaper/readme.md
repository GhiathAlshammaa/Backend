# Rock, Paper Scissor
Hey, you probably all have played rock, paper, scissor before. To quickly decide who pays, who goes first, or who get the first service in Ping Pong. 
This week we will build a simple Application where we can play this game. But we create in such a professional way that we can practice the new design principles like inter
## The Game
The game [rock-paper-scissors (wikipedia)](https://en.wikipedia.org/wiki/Rock%E2%80%93paper%E2%80%93scissors) consists of several abstractions. There are players. There are moves. And there are rules. There are rounds. First you should make sure that you solve the problem using the abstractions that you need. Start with pen and paper. 
**We don't need know the exact implementation to solve the problem, but we need to solve the problem to create the exact implementation.** But then for it to actually work, we need to think about the real *interface*. We can start however with defining the first classes we will use and basic responsibility.
The _interface_ is the "What exactly we want to do". 

## Pay attention to:
Design Principles
* Single Responsibility Principle
* KISS (Keep it simple, stupid)
* DRY (Don't Repeat Yourself)

Design Patterns
* Singleton (restricts the instantiation of a class to one object)
* Chain of Responsibility (allows passing request along the chain of potential handlers until one of them handles request. The pattern allows multiple objects to handle the request without coupling sender class to the concrete classes of the receivers.)

## Where to start:
1. First we think of the abstractions involved in this game. 
2. Make sure that we solve the problem in pseudo-classes and pseudo-code. What classes are we going to need?
3. Then we can start thinking about the actual code being written.

## Quotes
"Java is the art of not doing the job. It's about delegating the job to others that implement it then." - Guillermo
