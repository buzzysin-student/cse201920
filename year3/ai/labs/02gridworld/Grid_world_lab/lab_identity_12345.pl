get_clue(Clue) :-
    agent_ask_oracle(oscar, o(1), link, Clue).

% This is the main predicate, and should be true only when A is your identity
% find_identity(-A)
find_identity([A], _, A) :- !.
find_identity(Actors, Clues, A) :-
  % The expectation is that B shrinks with each call.
  % When there is only one actor remaining, the above
  % predicate takes over.
  findall(SomeActor,
        ( ( ( member(SomeActor, Actors)/* ,
              format("~w: has not been elimnated yet\n", [SomeActor])  */) 
          /* ; ( format("~w: has been eliminated\n", [SomeActor]), fail ) */),
          ( ( find_links_by_actor(SomeActor, SomeActorClues)/* ,
              format("~w: successfully found links (approx. ~w)\n", [SomeActor, S])  */)
          /* ; ( format("~w: could not load links.\n", [SomeActor]), fail ) */),
          ( ( forall( member(C, Clues)
                    , member(C, SomeActorClues) )/* ,
              format("~w: has the link on the page.\n", [SomeActor]) */ )
          /* ; ( format("~w: failed to find clue in their links.\n", [SomeActor]), fail ) */) ),
        NewActors),
  /* format("Considering: ~w\n", [Actors]), */
  /* format("Updated to : ~w\n", [NewActors]), */
  /* format("Given      : ~w\n", [Clues]), */
  /* writeln("==============="), */

  % Update clues
  get_clue(Clue),
  \+ member(Clue, Clues),
  append(Clues, [Clue], NewClues),

  find_identity(NewActors, NewClues, A).

find_identity(A) :-
    bagof(Actor, actor(Actor), Actors),
    find_identity(Actors, [], A).

% This is a helper predicate and should find all the links for a particular actor
% find_links_by_actor(+A,-L)
find_links_by_actor(A, Links) :-
    actor(A),
    wp(A, Text),
    findall(Link, wt_link(Text, Link), Links). 