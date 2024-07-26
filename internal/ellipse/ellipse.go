package ellipse

import (
	"math"
)

type Ellipse struct {
	rx, ry float64
}

func NewEllipse(radiusX, radiusY float64) *Ellipse {
	return &Ellipse{rx: radiusX, ry: radiusY}
}

func (e *Ellipse) Radius() float64 {
	return math.Max(e.rx, e.ry)
}

func (e *Ellipse) Step() float64 {
	return 0.0
}

func (e *Ellipse) Length() float64 {
	return math.Pi * (3*(e.rx+e.ry) - math.Sqrt((3*e.rx+e.ry)*(e.rx+3*e.ry)))
}

func (e *Ellipse) Curvature() float64 {
	return 1.0 / math.Max(e.rx, e.ry)
}

func (e *Ellipse) Evaluate(t float64) (x, y, z float64) {
	x = e.rx * math.Cos(t)
	y = e.ry * math.Sin(t)
	z = 0.0
	return
}

func (e *Ellipse) Derivative(t float64) (dx, dy, dz float64) {
	dx = -e.rx * math.Sin(t)
	dy = e.ry * math.Cos(t)
	dz = 0.0
	return
}
