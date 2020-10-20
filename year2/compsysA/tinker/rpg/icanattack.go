package main

// ICanAttack a contract to test whether an entity can attack
type ICanAttack interface {
	attack(e *Entity, atk *EntityAttack)
}
