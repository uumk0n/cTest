package main

import (
	"cTest/internal/circle"
	"cTest/internal/curve"
	"cTest/internal/ellipse"
	"cTest/internal/helix"
	"fmt"
	"math"
	"math/rand"
	"sort"
	"time"
)

func main() {
	rand.Seed(time.Now().UnixNano()) // Initialize random number generator

	// Create a slice to store curves
	var curves []curve.Curve3D

	// Populate with random curves
	for i := 0; i < 10; i++ {
		radius := float64(rand.Intn(10) + 1) // Random radius between 1 and 10
		step := float64(rand.Intn(10) + 1)   // Random step between 1 and 10
		typeID := rand.Intn(3)               // Random type: 0 - circle, 1 - ellipse, 2 - helix

		switch typeID {
		case 0:
			curves = append(curves, circle.NewCircle(radius))
		case 1:
			curves = append(curves, ellipse.NewEllipse(radius, radius/2))
		case 2:
			curves = append(curves, helix.NewHelix(radius, step))
		}
	}

	// Print coordinates and derivatives at t=PI/4
	t := math.Pi / 4
	for _, curve := range curves {
		x, y, z := curve.Evaluate(t)
		fmt.Printf("Point: (%f, %f, %f) ", x, y, z)

		dx, dy, dz := curve.Derivative(t)
		fmt.Printf("Derivative: (%f, %f, %f)\n", dx, dy, dz)
	}

	// Filter out only circles
	var circlesOnly []*circle.Circle
	for _, curve := range curves {
		if circle, ok := curve.(*circle.Circle); ok {
			circlesOnly = append(circlesOnly, circle)
		}
	}

	// Sort circles by radius
	sort.Slice(circlesOnly, func(i, j int) bool {
		return circlesOnly[i].Radius() < circlesOnly[j].Radius()
	})

	// Calculate the total sum of radii
	totalSumOfRadii := 0.0
	for _, circle := range circlesOnly {
		totalSumOfRadii += circle.Radius()
	}

	// Print the total sum of radii
	fmt.Printf("Total sum of radii in the second container: %f\n", totalSumOfRadii)
}
