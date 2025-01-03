class Solution:
    def fib(self, n):
        if n == 0:
            return 0
        elif n == 1:
            return 1

        def matrix_mult(A, B):
            return [
                [A[0][0] * B[0][0] + A[0][1] * B[1][0], A[0][0] * B[0][1] + A[0][1] * B[1][1]],
                [A[1][0] * B[0][0] + A[1][1] * B[1][0], A[1][0] * B[0][1] + A[1][1] * B[1][1]]
            ]

        def matrix_pow(matrix, power):
            result = [[1, 0], [0, 1]]  # Identity matrix
            base = matrix
            while power:
                if power % 2 == 1:
                    result = matrix_mult(result, base)
                base = matrix_mult(base, base)
                power //= 2
            return result

        # Fibonacci transformation matrix
        transformation = [[1, 1], [1, 0]]
        result_matrix = matrix_pow(transformation, n - 1)
        return result_matrix[0][0]  # F(n) is the top-left element
