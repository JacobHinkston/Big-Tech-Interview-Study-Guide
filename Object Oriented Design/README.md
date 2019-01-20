<h1>Object Oriented Design</h1>
<p>
    Object-oriented design questions require a candidate to sketch out the classes and methods to imple-ment technical problems or real-life objects. These problems give-or at least are believed to give- an interviewer insight into your coding style. These questions are not so much about regurgitating design patterns as they are about demonstrating that you understand how to create elegant, maintainable object-oriented code. Poor performance on this type of question may raise serious red flags.
</p>

<h2>> How to Approach</h2>
<p>
    Regardless of whether the object is a physical item or a technical task, object-oriented design questions can be tackled in similar ways.The following approach will work well for many problems.
</p>

<h3>Step 1: Handle Ambiguity</h3>
<p>
    Object-oriented design (000) questions are often intentionally vague in order to test whether you'll make assumptions or if you'll ask clarifying questions. After all, a developer who just codes something without understanding what she is expected to create wastes the company's time and money, and may create much more serious issues.
<br>
    When being asked an object-oriented design question, you should inquire who is going to use it and how they are going to use it. Depending on the question, you may even want to go through the "six Ws": who, what, where, when, how, why.
    For example, suppose you were asked to describe the object-oriented design for a coffee maker.This seems straightforward enough, right? Not quite.
<br>
    Your coffee maker might be an industrial machine designed to be used in a massive restaurant servicing hundreds of customers per hour and making ten different kinds of coffee products. Or it might be a very simple machine, designed to be used by the elderly for just simple black coffee.These use cases will Signifi-cantly impact your design.
</p>

<h3>Step 2: Define the Core Objects</h3>
<p>
    Now that we understand what we're designing, we should consider what the "core objects" in a system are. For example, suppose we are asked to do the object-oriented design for a restaurant. Our core objects might be things like Table, Guest, Party, Order, Meal, Employee, Server, and Host.
</p>

<h3>Step 3: Analyze Relationships</h3>

<p>
    Having more or less decided on our core objects, we now want to analyze the relationships between the objects. Which objects are members of which other objects? Do any objects inherit from any others? Are relationships many-to-many or one-to-many?
</p>
<p>
    For example, in the restaurant question, we may come up with the following design:
</p>
<ul>
    <li>Party should have an array of Guests.</li>
    <li>Server and Host inherit from Employee.</li>
    <li>Each Table has one Party, but each Party may have multiple Tables .</li>
    <li>There is one Host for the Restaurant.</li>
</ul>
<p>
    Be very careful here- you can often make incorrect assumptions. For example, a single T able may have multiple Part ies (as is common in the trendy "communal tables"at some restaurants). You should talk to your interviewer about how general purpose your design should be.
</p>
<h3>Step 4: Investigate Actions</h3>
<p>
    At this point, you should have the basic outline of your object-oriented design.What remains is to consider the key actions that the objects will take and how they relate to each other. You may find that you have forgotten some objects, and you will need to update your design.
</p>
<p>
    For example, a Party walks into the Restaurant, and a Guest requests a Table from the Host. The Host looks up the Reservation and, if it exists, assigns the Party to a Table.Otherwise, the Party is added to the end of the list. When a Party leaves, the Table is freed and assigned to a new Party in the list.
</p>
<h2>> Design Patterns</h2>
<p>
    Because interviewers are trying to test your capabilities and not your knowledge, design patterns are mostly beyond the scope of an interview. However, the Singleton and Factory Method design patterns are widely used in interviews, so we will cover them here.
</p>
<p>
    There are far more design patterns than this book could possibly discuss. A great way to improve your soft- ware engineering skills is to pick up abook that focuses on thisarea specifically.
</p>
<p>
    Be careful you don't fall into a trap of constantly trying to find the "right" design pattern for a particular problem. You should create the design that works for that problem. In some cases it might be an estab- lished pattern, but in many other cases it is not.
</p>

<h3>Singleton Class</h3>
<p>
The Singleton pattern ensures that a class has only one instance and ensures access to the instance through the application. It can be useful in cases where you have a "global" object with exactly one instance. For example, we may want to implement Restaurant such that it has exactly one instance of Restaurant.
</p>
<code> 
    (JAVA)
    public class Resturant{
      <br>
        private static Resturant _instance = null;
        <br>
        protected Resturant(){...};
        <br>
         public static Resturant getInstance(){
          <br>
            if(_instance == null){
              <br>
                _instance = new Resturant();
                <br>
            }
            <br>
            return _instance;
            <br>
        }
        <br>
    }
</code>
<p> It should be noted that many people dislike the Singleton design pattern, even calling it an "anti-pattern:' One reason for this is that it can interfere with unit testing.</p>
<h3>Factory Method</h3>
<p>
    The Factory Method offers an interface for creating an instance of a class, with its subclasses deciding which class to instantiate. You might want to implement this with the creator class being abstract and not providing an implementation for the Factory method. Or, you could have the Creator class be a concrete class that provides an implementation for the Factory method. In this case, the Factory method would take a parameter representing which class to instantiate.
</p>
<code>
    public class CardGame{
        <br>
        public static CardGame createCardGame(GameType type){
            <br>
            if(type == GameType.Poker){
                return new PokerGame();
            } <br> else if (type == GameType.BlackJack){
                return new BlackJackGame();
            } 
            <br>return null;
        <br>
        }
    }
</code>
<h3>---- Interview Questions ----</h3>
<p>
  <b>Interview Question 7.2: Call Center.</b>
  <br>
  Imagine you have a call center with three levels of employees: respondent, manager, and director. 
  An incoming telephone call must be first allocated to a respondent who is free. 
  If the respondent can't handle the call, he or she must escalate the call to a manager. 
  If the manager is not free or not able tso handle it, then the call should be escalated to a director. 
  Design the classes and data structures for this problem. 
  Implement a method dispatchCall() which assigns a call to the first available employee.
<p>

<p>
    <b>Interview Question 7.3: Jukebox.</b>
    <br>
    Design a musical jukebox using object-oriented principles..
</p>
<p>
 <b>Interview Question 7.4: Parking Lot.</b>
<br>
  Design a parking lot using object-oriented principles.
</p>
<p>
  <b>Interview Question 7.5: Online Book Reader.</b>
  <br>
  Design the data structures for an online book reader system.

</p>
<p>
  <b>Interview Question 7.6: Jigsaw.</b>
  <br>
  Implement an NxN jigsaw puzzle. Design the data structures and explain an algorithm to solve the puzzle. You can assume that you have a fitsWith method which, when passed two puzzle edges, returns true if the two edges belong together.
</p>
<p>
  <b>Interview Question 7.7: Chat Server.</b>
  <br>
  Explain how you would design a chat server. In particular, provide details about the various backend components, classes, and methods. What would be the hardest problems to solve?
</p>
<p>
   <b>Interview Question 7.8: Othello.</b>
  <br>
Othello is played as follows: Each Othello piece is white on one side and black on the other. When a piece is surrounded by its opponents on both the left and right sides, or both the top and bottom, it is said to be captured and its color is flipped. On your turn, you must capture at least one of your opponent's pieces. The game ends when either user has no more valid moves. The win is assigned to the person with the most pieces. Implement the object-oriented design for Othello.
</p>

<p>
    <b>Interview Question 7.9: CircularArray.</b>
    <br>
    Implement a Circular Array class that supports an array-like data structure which can be efficiently rotated. If possible, the class should use a generic type (also called a template), and should support iteration via the standard for (Obj 0 : circularArray) notation.
</p>