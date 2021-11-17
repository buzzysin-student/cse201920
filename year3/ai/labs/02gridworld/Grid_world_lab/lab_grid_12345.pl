% True if A is a possible movement direction
m(n). % North
m(e). % South
m(s). % East
m(w). % West

% True if p(X,Y) is on the board
on_board(p(X, Y)) :-
  ailp_grid_size(S),    % Extract the size of the grid
  between(1, S, X),     % Check X bounds
  between(1, S, Y).     % Check Y bounds
  

% True if p(X1,Y1) is one step in direction M from p(X,Y) (no bounds check)
pos_step(p(X, Y), M, p(X1, Y1)) :-
   m(M),
  (M = n, Y1 is (Y - 1), X1 = X) ; % North is a -1 change in Y
  (M = e, X1 is (X + 1), Y1 = Y) ; % East is a  +1 change in X
  (M = s, Y1 is (Y + 1), X1 = X) ; % South is a +1 change in Y
  (M = w, X1 is (X - 1), Y1 = Y) . % West is a  -1 change is X
  

% True if NPos is one step in direction M from Pos (with bounds check)
new_pos(Pos, M, NPos) :-
  on_board(Pos),            % Find and instantiate Pos
  pos_step(Pos, M, NPos),   % Find and instantiate M and NPos
  on_board(NPos).           % Validate NPos on the grid.

% True if a L has the same length as the number of squares on the board
complete(L) :- 
  ailp_grid_size(N),        % Find the dimension of the grid
  NumSquares is N*N,        % Calculate the number of squares
  length(L, NumSquares).    % `L` is a list with `NumSquares` entries

dbg(S, T):-
  write(S), write(" = "), write_term(T, []), nl.
dbg(S, T, TT):-
  dbg(S, T), sleep(TT).
  
% Define turns (clockwise)
turn(M, N):-
  m(M), m(N),
  M = e, N = s ;
  M = s, N = w ;
  M = w, N = n ;
  M = n, N = e.
    
% Perform a sequence of moves creating a spiral pattern, return the moves as L
% helper function: +A, +Step, +V, -L
spiral(A, _, V, L):- complete([A|V]), !, reverse([A|V], L).
spiral(A, Step, V, L) :-
    (   Next=Step
    ;   turn(Step, Next) ),
    new_pos(A, Next, B),
    \+ member(B, V), !,
    W=[A|V],
    spiral(B, Next, W, L).

spiral(L):-
  my_agent(Agent),
  get_agent_position(Agent, P),
  complete(L),
  spiral(P, 'e', [], L).

fuck :-
  catch(
    stop, 
    _,
    (
      start, 
      join_game(_),
      reset_game,
      start_game
    )
  ).

/** <examples>
 * ?- start , shell .
 * ?- on_board(P).
 */
