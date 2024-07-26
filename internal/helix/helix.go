package helix

import (
	"math"
)

type Helix struct {
	r, s float64
}

func NewHelix(radius, step float64) *Helix {
	return &Helix{r: radius, s: step}
}

func (h *Helix) Radius() float64 {
	return h.r
}

func (h *Helix) Step() float64 {
	return h.s
}

func (h *Helix) Length() float64 {
	return 2.0 * math.Pi * h.r
}

func (h *Helix) Curvature() float64 {
	return 1.0 / h.r
}

func (h *Helix) Evaluate(t float64) (x, y, z float64) {
	x = h.r * math.Cos(t)
	y = h.r * math.Sin(t)
	z = h.s * t / (2.0 * math.Pi)
	return
}

func (h *Helix) Derivative(t float64) (dx, dy, dz float64) {
	dx = -h.r * math.Sin(t)
	dy = h.r * math.Cos(t)
	dz = h.s / (2.0 * math.Pi)
	return
}
