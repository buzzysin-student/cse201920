:- dynamic antecedant/2, consequant/2.

commitment(S, _, A, C) :-
    A,
    consequant(S, C).

prohibition(S, _, A, C) :-
    A,
    consequant(S, \+C).

authorisation(S, _, A, _) :-
    A,
    consequant(S, _).

power(S, O, A, C) :-
    antecedant(O, A),
    consequant(S, C).

sanction(_, O, A, C) :-
    A,
    consequant(O, C).

norm(N) :-
    (   N=commitment(_, _, _, _)
    ;   N=prohibition(_, _, _, _)
    ;   N=authorisation(_, _, _, _)
    ;   N=power(_, _, _, _)
    ;   N=sanction(_, _, _, _)
    ).

norm(commitment(student, university, lecturescheduled, attendlecture)).

c_create(S, O, A, C) :-
    S,
    commitment(S, O, A, C).

c_cancel(S, O, A, C) :-
    S,
    \+ commitment(S, O, A, C).

c_release(S, O, A, C) :-
    O,
    \+ commitment(S, O, A, C).

c_delegate(S1, O, S2, A, C) :-
    S1,
    commitment(S2, O, A, C).

c_assign(S, O1, O2, A, C) :-
    O1,
    commitment(S, O2, A, C).

