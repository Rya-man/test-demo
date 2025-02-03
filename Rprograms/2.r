# Load dplyr for data manipulation
#install.packages("dplyr")
library(dplyr)

# Initialize an empty data frame for student data
student_data <- data.frame(
  Name = character(),
  Math_Score = numeric(),
  Science_Score = numeric(),
  History_Score = numeric(),
  Attendance = numeric()
)

# Function to add student data
add_student <- function(name, math_score, science_score, history_score, attendance) {
  new_student <- data.frame(Name = name, Math_Score = math_score, Science_Score = science_score, 
                            History_Score = history_score, Attendance = attendance)
  student_data <<- bind_rows(student_data, new_student)
  cat("Student added.\n")
}

# Function to calculate average scores
calculate_avg_scores <- function() {
  student_data %>%
    mutate(Average_Score = (Math_Score + Science_Score + History_Score) / 3) %>%
    select(Name, Average_Score)
}

# Function to identify students with low attendance (below threshold)
identify_low_attendance <- function(threshold) {
  student_data %>%
    filter(Attendance < threshold) %>%
    select(Name, Attendance)
}

# Function to generate a report
generate_report <- function() {
  avg_scores <- calculate_avg_scores()
  low_attendance <- identify_low_attendance(70)
  
  # Merge average scores with attendance data
  report <- merge(avg_scores, low_attendance, by = "Name", all = TRUE)
  report$Attendance[is.na(report$Attendance)] <- 100  # Fill NA attendance with 100%
  
  cat("Performance Report:\n")
  print(report)
}

# Main program loop
while (TRUE) {
  cat("\n1. Add Student\n2. Generate Report\n3. Exit\n")
  choice <- as.integer(readline("Enter choice: "))
  
  if (choice == 1) {
    name <- readline("Enter student name: ")
    math_score <- as.numeric(readline("Enter math score: "))
    science_score <- as.numeric(readline("Enter science score: "))
    history_score <- as.numeric(readline("Enter history score: "))
    attendance <- as.numeric(readline("Enter attendance percentage: "))
    add_student(name, math_score, science_score, history_score, attendance)
  } else if (choice == 2) {
    generate_report()
  } else if (choice == 3) {
    cat("Exiting the program.\n")
    break
  } else {
    cat("Invalid choice. Try again.\n")
  }
}
