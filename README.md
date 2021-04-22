# Task Scheduler
 > Authors: [Sumit Gupta](https://github.com/sumitgupta314), [Jordan Sam](https://github.com/Jsam88), [Benson Wan](https://github.com/iarebwan)

## Project Description
## Phase I
 > * This project is important to us because we believe it would be fun and useful to create a program that will benefit people in their everyday lives. It also has the potential to be used by a large population of people who would like to create a schedule to keep themselves more organized. Before someone makes the mistake of double booking themselves and failing to properly manage their time, they will now have the chance to prevent that. Not only will it help us as people to become more organized, but we will also utilize new strategies and skills learned from this CS100 course.
 > * Languages/Tools/Technologies:
 >   * [C++](https://www.cplusplus.com/) - Using this middle level language, we will create a console interface in which the client has the ability to input commands from the keyboard to utilize the system while also displaying the inputs on screen.
 >   * [CMake](https://cmake.org/) - We will use CMake for build automation and compiling our program.
 >   * [Git](https://git-scm.com/) - We will use Git as the version control tool to coordinate work, keep track of changes in our code, and keep our project up to date. 
 >   * [Valgrind](https://valgrind.org/) - We will use the Valgrind framework to construct dyanmic analysis tools to help us with memory debugging and detecting memory leaks.
 > * The inputs of our project would be times, dates, and the task descriptions. We are planning on using the twelve hour clock time period for the time input as well as the options for days, weeks, and months for the date input, and the task description will just be anything the user enters to describe the certain task being scheduled. The outputs would be the actual scheduled task displayed for the user to view and also approvals/denials for the task to be scheduled depending on whether the inputs are valid. 
 > * The two design patterns that we plan to use are the Composite and Strategy pattern.
 >   * We are going to use the composite pattern because it would be easier to add new components if we want to implement and improve our original system. Given that the design pattern is very flexible, we will be able to create both primitive and complex objects for our classes (class hierarchies) in an ideal, organized way. The feature that we want to implement with it is the display system for both the different kinds of tasks (schedule and task lists). A problem that we anticipate encountering while working on our project that the composite pattern will solve is disorganization. We can create a class of folders that essentially holds all of the created schedules that are made.
 >   * We will also be using the strategy design pattern to let the program determine at runtime which class/function to use. This way, based on user choices it can be determined during runtime which classes will be used to fulfill a job the user requests. The feature we will implement with this design pattern is printing out the user’s data. Since each user can have lots of different categories of data in their task scheduler account such as the type of task (professional, academic, personal, etc), the task due date, title, description, among others, the strategy pattern can determine during runtime what classes need to be used to display the data the user wants. The problem we can face is having too much code in displaying various types of data, and the strategy pattern can help with simplifying the code. 

 > ## Phase II
 > In addition to completing the "Class Diagram" section below, you will need to 
 > * Set up your GitHub project board as a Kanban board for the project. It should have columns that map roughly to 
 >   * Backlog, TODO, In progress, In testing, Done
 >   * You can change these or add more if you'd like, but we should be able to identify at least these.
 > * There is no requirement for automation in the project board but feel free to explore those options.
 > * Create an "Epic" (note) for each feature and each design pattern and assign them to the appropriate team member. Place these in the `Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Create smaller development tasks as issues and assign them to team members. Place these in the `TODO` column.
 >   * These cards should represent roughly 7 days worth of development time for your team, taking you until your first meeting with the TA
## Class Diagram
 > Include a class diagram(s) for each design pattern and a description of the diagram(s). Your class diagram(s) should include all the main classes you plan for the project. This should be in sufficient detail that another group could pick up the project this point and successfully complete it. Use proper OMT notation (as discussed in the course slides). You may combine multiple design patterns into one diagram if you'd like, but it needs to be clear which portion of the diagram represents which design pattern (either in the diagram or in the description). 
 
 > ## Phase III
 > You will need to schedule a check-in with the TA (during lab hours or office hours). Your entire team must be present. 
 > * Before the meeting you should perform a sprint plan like you did in Phase II
 > * In the meeting with your TA you will discuss: 
 >   - How effective your last sprint was (each member should talk about what they did)
 >   - Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 >   - Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 >   - What tasks you are planning for this next sprint.

 > ## Final deliverable
 > All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
