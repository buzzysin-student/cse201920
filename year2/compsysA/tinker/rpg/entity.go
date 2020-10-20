package main

// EntityType the type of entity
type EntityType int

const (
	abstract EntityType = iota
	player
	monster
)

// EntityAttack the type of attack
type EntityAttack struct {
	name      string
	power     int
	attribute Attribute
}

// Entity the type of Entity
type Entity struct {
	name       string
	hp         int
	mp         int
	level      int
	entityType *EntityType
	attribute  *Attribute
	attacks    []*EntityAttack
}

// EntityConfig use to configure entities
type EntityConfig Entity

// EntityNew function that creates a new entity
func EntityNew(config *EntityConfig) *Entity {
	e := Entity{}
	e.name = config.name
	e.hp = config.hp
	e.mp = config.mp
	e.level = config.level
	e.entityType = config.entityType
	e.attribute = config.attribute
	return &e
}
