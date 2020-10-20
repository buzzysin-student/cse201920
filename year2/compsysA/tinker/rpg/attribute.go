package main

// Attribute The type of element
type Attribute int

// Enum containing elemental Attributes
const (
	WATER Attribute = iota
	FIRE
	AIR
	EARTH
)

func (a *Attribute) compare(b *Attribute) float64 {
	if (*a+1)%4 == *b {
		return 2
	} else if (*a+2)%4 == *b {
		return 1.5
	} else if (*a+3)%4 == *b {
		return 0.75
	} else {
		return 0.5
	}
}

func (a *Attribute) name() string {
	switch *a {
	case WATER:
		return "water"
	case FIRE:
		return "fire"
	case AIR:
		return "air"
	case EARTH:
		return "earth"
	default:
		return "aether"
	}
}
