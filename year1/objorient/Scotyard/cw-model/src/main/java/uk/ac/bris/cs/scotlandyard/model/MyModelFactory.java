package uk.ac.bris.cs.scotlandyard.model;

import javax.annotation.Nonnull;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;

import uk.ac.bris.cs.scotlandyard.model.Board.GameState;
import uk.ac.bris.cs.scotlandyard.model.Model.Observer.Event;
import uk.ac.bris.cs.scotlandyard.model.ScotlandYard.Factory;

/**
 * cw-model Stage 2: Complete this class
 */
public final class MyModelFactory implements Factory<Model> {

  @Override
  @Nonnull
  public Model build(final GameSetup setup, final Player mrX, final ImmutableList<Player> detectives) {

    return new Model() {

      // ! Initialisation without constructor? Kill it with fire!
      public GameState state = new MyGameStateFactory().build(setup, mrX, detectives);
      public ImmutableSet<Observer> observers = ImmutableSet.of();

      @Override
      @Nonnull
      public Board getCurrentBoard() {
        return state;
      }

      @Override
      @Nonnull
      public ImmutableSet<Observer> getObservers() {
        return observers;
      }

      @Override
      public void registerObserver(@Nonnull final Observer observer) {
        if (observer.equals(null))
          throw new IllegalArgumentException();
        if (observers.contains(observer))
          throw new IllegalArgumentException();
        observers = ImmutableSet.<Observer>builder().addAll(observers).add(observer).build();
      }

      @Override
      public void unregisterObserver(@Nonnull final Observer observer) {
        if (observer.equals(null))
          throw new IllegalArgumentException();
        if (!observers.contains(observer))
          throw new IllegalArgumentException();

        observers = ImmutableSet
            .copyOf(observers.stream().filter(o -> !o.equals(observer)).collect(ImmutableSet.toImmutableSet()));
      }

      @Override
      public void chooseMove(@Nonnull final Move move) {
        state = state.advance(move);
        var event = state.getWinner().isEmpty() ? Event.MOVE_MADE : Event.GAME_OVER;
        for (Observer o : observers)
          o.onModelChanged(state, event);
      }

    };
  }

}
