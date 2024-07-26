package circle

import (
	"math"
)

type Circle struct {
	r float64
}

func NewCircle(radius float64) *Circle {
	return &Circle{r: radius}
}

func (c *Circle) Radius() float64 {
	return c.r
}

func (c *Circle) Step() float64 {
	return 0.0
}

func (c *Circle) Length() float64 {
	return 2.0 * math.Pi * c.r
}

func (c *Circle) Curvature() float64 {
	return 1.0 / c.r
}

func (c *Circle) Evaluate(t float64) (x, y, z float64) {
	x = c.r * math.Cos(t)
	y = c.r * math.Sin(t)
	z = 0.0
	return
}

func (c *Circle) Derivative(t float64) (dx, dy, dz float64) {
	dx = -c.r * math.Sin(t)
	dy = c.r * math.Cos(t)
	dz = 0.0
	return
}
