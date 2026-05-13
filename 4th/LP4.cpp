# -----------------------------------------
# FUNCTION TO CHECK SAFE POSITION
# -----------------------------------------

def is_safe(board, row, col, n):


    # -----------------------------------------
    # CHECK SAME COLUMN
    # -----------------------------------------

    # Loop from row 0 to current row-1

    for i in range(row):


        # board[i] stores column number
        # where queen is already placed

        # Example:
        # board[0] = 2
        # Means queen placed at:
        # row 0 column 2

        # If queen already exists
        # in same column

        if board[i] == col:


            # Position unsafe

            return False



    # -----------------------------------------
    # CHECK LEFT DIAGONAL
    # -----------------------------------------

    # zip() combines two loops together

    # range(row-1,-1,-1)
    # moves upward row-wise

    # range(col-1,-1,-1)
    # moves toward left side

    for i, j in zip(
            range(row - 1, -1, -1),
            range(col - 1, -1, -1)
    ):


        # If queen found
        # on left diagonal

        if board[i] == j:


            # Unsafe position

            return False



    # -----------------------------------------
    # CHECK RIGHT DIAGONAL
    # -----------------------------------------

    # range(col+1,n)
    # moves toward right side

    for i, j in zip(
            range(row - 1, -1, -1),
            range(col + 1, n)
    ):


        # If queen found
        # on right diagonal

        if board[i] == j:


            # Unsafe position

            return False



    # -----------------------------------------
    # SAFE POSITION
    # -----------------------------------------

    # No queen attacks current position

    return True




# -----------------------------------------
# BACKTRACKING FUNCTION
# -----------------------------------------

def solve_backtracking(n):


    # -----------------------------------------
    # CREATE BOARD ARRAY
    # -----------------------------------------

    # -1 means empty row

    # Example for n=4

    # [-1,-1,-1,-1]

    board = [-1] * n



    # -----------------------------------------
    # RECURSIVE FUNCTION
    # -----------------------------------------

    def solve(row):


        # -----------------------------------------
        # BASE CONDITION
        # -----------------------------------------

        # If row becomes equal to n

        # Means all queens placed

        if row == n:


            # Print solution

            print("Backtracking Solution:", board)


            # Return True

            return True



        # -----------------------------------------
        # TRY ALL COLUMNS
        # -----------------------------------------

        for col in range(n):


            # -----------------------------------------
            # CHECK SAFE POSITION
            # -----------------------------------------

            if is_safe(board, row, col, n):


                # -----------------------------------------
                # PLACE QUEEN
                # -----------------------------------------

                # Example:
                # board[2]=1

                # Means queen at:
                # row 2 column 1

                board[row] = col



                # -----------------------------------------
                # RECURSIVE CALL
                # -----------------------------------------

                # Move to next row

                if solve(row + 1):


                    # If solution found

                    return True



        # -----------------------------------------
        # NO VALID POSITION
        # -----------------------------------------

        # Backtrack

        return False



    # -----------------------------------------
    # START FROM ROW 0
    # -----------------------------------------

    solve(0)




# -----------------------------------------
# BRANCH AND BOUND FUNCTION
# -----------------------------------------

def solve_branch_and_bound(n):


    # -----------------------------------------
    # CREATE BOARD ARRAY
    # -----------------------------------------

    board = [-1] * n



    # -----------------------------------------
    # COLUMN ARRAY
    # -----------------------------------------

    # Stores occupied columns

    cols = [False] * n



    # -----------------------------------------
    # LEFT DIAGONAL ARRAY
    # -----------------------------------------

    # Formula:
    # row + col

    diag1 = [False] * (2 * n)



    # -----------------------------------------
    # RIGHT DIAGONAL ARRAY
    # -----------------------------------------

    # Formula:
    # row-col+n-1

    diag2 = [False] * (2 * n)



    # -----------------------------------------
    # RECURSIVE FUNCTION
    # -----------------------------------------

    def solve(row):


        # -----------------------------------------
        # BASE CONDITION
        # -----------------------------------------

        if row == n:


            # Print solution

            print("Branch & Bound Solution:", board)


            return True



        # -----------------------------------------
        # TRY EVERY COLUMN
        # -----------------------------------------

        for col in range(n):


            # -----------------------------------------
            # CHECK SAFE POSITION
            # -----------------------------------------

            # not cols[col]
            # checks column free or not

            # not diag1[row+col]
            # checks left diagonal

            # not diag2[row-col+n-1]
            # checks right diagonal

            if (
                not cols[col]
                and
                not diag1[row + col]
                and
                not diag2[row - col + n - 1]
            ):


                # -----------------------------------------
                # PLACE QUEEN
                # -----------------------------------------

                board[row] = col



                # Mark column occupied

                cols[col] = True



                # Mark left diagonal occupied

                diag1[row + col] = True



                # Mark right diagonal occupied

                diag2[row - col + n - 1] = True



                # -----------------------------------------
                # RECURSIVE CALL
                # -----------------------------------------

                if solve(row + 1):


                    return True



                # -----------------------------------------
                # BACKTRACKING STEP
                # -----------------------------------------

                # Remove queen

                cols[col] = False

                diag1[row + col] = False

                diag2[row - col + n - 1] = False



        # -----------------------------------------
        # NO SOLUTION FOUND
        # -----------------------------------------

        return False



    # -----------------------------------------
    # START FROM ROW 0
    # -----------------------------------------

    solve(0)




# -----------------------------------------
# MAIN PROGRAM
# -----------------------------------------

# Take number of queens from user

n = int(input("Enter number of queens: "))



# Call backtracking solution

solve_backtracking(n)



# Call branch and bound solution

solve_branch_and_bound(n)