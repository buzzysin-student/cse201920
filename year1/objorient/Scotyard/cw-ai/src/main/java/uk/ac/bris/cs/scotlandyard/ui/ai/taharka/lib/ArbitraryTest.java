package uk.ac.bris.cs.scotlandyard.ui.ai.taharka.lib;

import java.io.IOException;
import java.util.Optional;
import java.util.Random;
import java.util.function.Supplier;

import com.google.common.collect.ImmutableList;
import com.google.common.collect.ImmutableSet;
import com.google.common.graph.ImmutableValueGraph;

import uk.ac.bris.cs.scotlandyard.model.Board;
import uk.ac.bris.cs.scotlandyard.model.Board.GameState;
import uk.ac.bris.cs.scotlandyard.model.GameSetup;
import uk.ac.bris.cs.scotlandyard.model.LogEntry;
import uk.ac.bris.cs.scotlandyard.model.Move;
import uk.ac.bris.cs.scotlandyard.model.MyGameStateFactory;
import uk.ac.bris.cs.scotlandyard.model.Piece;
import uk.ac.bris.cs.scotlandyard.model.Piece.Detective;
import uk.ac.bris.cs.scotlandyard.model.Piece.MrX;
import uk.ac.bris.cs.scotlandyard.model.Player;
import uk.ac.bris.cs.scotlandyard.model.ScotlandYard;
import uk.ac.bris.cs.scotlandyard.model.ScotlandYard.Transport;

public class ArbitraryTest {

  public static Supplier<ImmutableValueGraph<Integer, ImmutableSet<Transport>>> scotyard = () -> {
    try {
      return ScotlandYard.standardGraph();
    } catch (IOException e) {
      e.printStackTrace();
      return null;
    }
  };

  public static GameSetup setup = new GameSetup(scotyard.get(), ScotlandYard.STANDARD24ROUNDS);

  public static GameState state = new MyGameStateFactory().build(setup,
      new Player(MrX.MRX, ScotlandYard.defaultMrXTickets(), 199), ImmutableList.of(/*  */
          new Player(Detective.RED, ScotlandYard.defaultDetectiveTickets(), new Random().nextInt(198) + 1),
          new Player(Detective.YELLOW, ScotlandYard.defaultDetectiveTickets(), new Random().nextInt(198) + 1),
          new Player(Detective.BLUE, ScotlandYard.defaultDetectiveTickets(), new Random().nextInt(198) + 1),
          new Player(Detective.GREEN, ScotlandYard.defaultDetectiveTickets(), new Random().nextInt(198) + 1),
          new Player(Detective.WHITE, ScotlandYard.defaultDetectiveTickets(), new Random().nextInt(198) + 1)));

  public static Board staticboard = new Board() {

    @Override
    public ImmutableSet<Move> getAvailableMoves() {
      return state.getAvailableMoves();
    }

    @Override
    public Optional<Integer> getDetectiveLocation(Detective arg0) {
      return state.getDetectiveLocation(arg0);
    }

    @Override
    public ImmutableList<LogEntry> getMrXTravelLog() {
      return state.getMrXTravelLog();
    }

    @Override
    public Optional<TicketBoard> getPlayerTickets(Piece arg0) {
      return state.getPlayerTickets(arg0);
    }

    @Override
    public ImmutableSet<Piece> getPlayers() {
      return state.getPlayers();
    }

    @Override
    public GameSetup getSetup() {
      return state.getSetup();
    }

    @Override
    public ImmutableSet<Piece> getWinner() {
      return state.getWinner();
    }

  };
}