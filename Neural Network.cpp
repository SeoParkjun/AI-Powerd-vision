public static Complex[] Quartic(double a, double b, double c, double d) {

        Complex[] root = new Complex[4];

        Complex[] cubicRoots = SolveCubic(1.0, -b, (a * c - 4.0 * d), ( 4.0 * b * d - c * c - a * a * d));

        Complex y = cubicRoots[0];

        Complex R = Complex.Sqrt(0.25 * a * a - b + y);

        Complex D, E;
        if (R.Magnitude > 1E-5) {
            D = Complex.Sqrt(0.75 * (a * a) - R * R - 2.0 * b + (4.0 * a * b - 8.0 * c - a * a * a) / (4.0 * R));
            E = Complex.Sqrt(0.75 * (a * a) - R * R - 2.0 * b - (4.0 * a * b - 8.0 * c - a * a * a) / (4.0 * R));
        } else {
            D = Complex.Sqrt(0.75 * a * a - 2.0 * b + 2.0 * Complex.Sqrt(y * y - 4.0 * d));
            E = Complex.Sqrt(0.75 * a * a - 2.0 * b - 2.0 * Complex.Sqrt(y * y - 4.0 * d));
        }
        root[0] = -0.25 * a + 0.5 * R + 0.5 * D;
        root[1] = -0.25 * a + 0.5 * R - 0.5 * D;
        root[2] = -0.25 * a - 0.5 * R + 0.5 * E;
        root[3] = -0.25 * a - 0.5 * R - 0.5 * E;
        return root;
    }
