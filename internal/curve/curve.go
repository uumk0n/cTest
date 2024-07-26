package curve

type Curve3D interface {
	Radius() float64
	Step() float64
	Length() float64
	Curvature() float64
	Evaluate(t float64) (x, y, z float64)
	Derivative(t float64) (dx, dy, dz float64)
}
