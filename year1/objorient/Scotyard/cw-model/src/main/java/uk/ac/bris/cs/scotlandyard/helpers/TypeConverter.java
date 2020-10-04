package uk.ac.bris.cs.scotlandyard.helpers;

import java.util.function.Function;

import com.google.common.collect.ImmutableList;

/**
 * Helper: A class that arises when you're tired of using streams inside of
 * streams for mapping, or converting between types
 * 
 * <blockquote><em>&mdash; Taharka O.</em></blockquote>
 */
public class TypeConverter<T, U> {
  /**
   * A function used for converting T to U
   */
  private final Function<T, U> f1;
  /**
   * A function used for converting U to T
   */
  private final Function<U, T> f2;

  /**
   * Provide this contstructor with functions needed to convert between types
   * 
   * @param f1 f: T -> U (conversion)
   * @param f2 f: U -> T (reversion)
   */
  public TypeConverter(final Function<T, U> f1, final Function<U, T> f2) {
    this.f1 = f1;
    this.f2 = f2;
  }

  /**
   * @param target what to convert
   * @return a T-type item converted into a U-type item
   */
  public U convert(final T target) {
    return f1.apply(target);
  }

  /**
   * @param target what to revert
   * @return a U-type item reverted into a T-type item
   */
  public T revert(final U target) {
    return f2.apply(target);
  }

  /**
   * @param target what to convert
   * @return T-type items converted into U-type items
   * @apiNote a {@code Collectors} class of sorts is required to use the result of
   *          this if the interface of {@code Iterable<E>} is not enough
   */
  public Iterable<U> convert(final Iterable<T> target) {
    return ImmutableList.copyOf(target).stream().map(f1).collect(ImmutableList.toImmutableList());
  }

  /**
   * @param target what to revert
   * @return U-type items reverted into T-type items
   * @apiNote a {@code Collectors} class of sorts is required to use the result of
   *          this if the interface of {@code Iterable<E>} is not enough
   */
  public Iterable<T> revert(final Iterable<U> target) {
    return ImmutableList.copyOf(target).stream().map(f2).collect(ImmutableList.toImmutableList());
  }

}