# Read student data from a file, calculate the average score, and list students with scores above average

# Open the input file for reading
try:
    with open('students.txt', 'r') as file:
        lines = file.readlines()
except FileNotFoundError:
    print("Error: Unable to open input file.")
    exit(1)

# Initialize lists to store student names and scores
names = []
scores = []

# Parse data from each line in the file
for line in lines:
    parts = line.split()
    if len(parts) == 2:
        name, score = parts
        names.append(name)
        scores.append(int(score))

# Check if any data was read
if not names:
    print("Error: No data found in the input file.")
    exit(1)

# Calculate the average score
average_score = sum(scores) / len(scores)

print(f"Average Score: {average_score}")
print("Students with Scores Above Average:")
for name, score in zip(names, scores):
    if score > average_score:
        print(f"{name} ({score})")
