package main

// Player the type that describes the player entity
type Player struct {
	Entity
}

// PlayerConfig the type that describes the config for the player entity
type PlayerConfig struct {
	EntityConfig
}

// PlayerNew function that creates a new player entity
func PlayerNew(config *PlayerConfig) *Player {
	e := EntityNew(&config.EntityConfig)
	*e.entityType = player
	return &Player{Entity: *e}
}

func (p *Player) attack(other *Entity, atk *EntityAttack) {
	// attrBonus := Ternary(atk.attribute == *p.attribute, 1.1, 1).(float64) * atk.attribute.compare(other.attribute)
	// levelBonus := Clamp(1.5, 0.1, (float64(p.level-other.level) / float64(p.level)))
}
