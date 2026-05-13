# -----------------------------------------
# HOSPITAL EXPERT SYSTEM
# -----------------------------------------



# -----------------------------------------
# FUNCTION DEFINITION
# -----------------------------------------

# def keyword is used to create function

# hospital_expert_system is function name

def hospital_expert_system():



    # -----------------------------------------
    # WELCOME MESSAGE
    # -----------------------------------------

    # print() displays output on screen

    print("🏥 Welcome to Hospital Expert System")



    # Instruction message

    print("Answer the following questions.")



    # \n means new line

    print("Type 'yes' or 'no'\n")



    # -----------------------------------------
    # USER INPUT SECTION
    # -----------------------------------------

    # input() takes input from user

    # .lower() converts input into lowercase

    # Example:
    # YES -> yes

    # fever variable stores fever response

    fever = input("Do you have fever? ").lower()



    # cough variable stores cough response

    cough = input("Do you have cough? ").lower()



    # chest_pain variable stores chest pain response

    chest_pain = input("Do you have chest pain? ").lower()



    # injury variable stores injury response

    injury = input("Do you have any injury or fracture? ").lower()



    # stomach_pain variable stores stomach pain response

    stomach_pain = input("Do you have stomach pain? ").lower()



    # -----------------------------------------
    # DIAGNOSIS HEADING
    # -----------------------------------------

    print("\n--- Diagnosis Suggestion ---")



    # -----------------------------------------
    # FIRST CONDITION
    # -----------------------------------------

    # Checks:
    # fever == yes
    # AND
    # cough == yes

    # and operator means:
    # both conditions must become true

    if fever == "yes" and cough == "yes":



        # Diagnosis message

        print("You may have a viral infection or flu.")



        # Suggested medical department

        print("Suggested Department: General Medicine")



    # -----------------------------------------
    # SECOND CONDITION
    # -----------------------------------------

    # Checks chest pain condition

    elif chest_pain == "yes":



        # Heart-related diagnosis

        print("You may need a heart check-up.")



        # Suggested department

        print("Suggested Department: Cardiology")



    # -----------------------------------------
    # THIRD CONDITION
    # -----------------------------------------

    # Checks injury condition

    elif injury == "yes":



        # Injury diagnosis

        print("You may require bone or injury treatment.")



        # Suggested department

        print("Suggested Department: Orthopedics")



    # -----------------------------------------
    # FOURTH CONDITION
    # -----------------------------------------

    # Checks stomach pain condition

    elif stomach_pain == "yes":



        # Digestive issue diagnosis

        print("You may have digestive issues.")



        # Suggested department

        print("Suggested Department: Gastroenterology")



    # -----------------------------------------
    # DEFAULT CONDITION
    # -----------------------------------------

    # Executes if all conditions become false

    else:



        # General suggestion

        print("Please consult a General Physician for further diagnosis.")



    # -----------------------------------------
    # FINAL MESSAGE
    # -----------------------------------------

    print("\nThank you for using Hospital Expert System.")




# -----------------------------------------
# FUNCTION CALL
# -----------------------------------------

# Starts program execution

hospital_expert_system()