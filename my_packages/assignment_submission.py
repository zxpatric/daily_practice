from typing import Optional, List
from datetime import datetime


class Submission:
    def __init__(self, student_name, submitted_at, content):
        self.score: Optional[float] = None  # Score can be None if not graded yet
        self.student_name = student_name
        self.submitted_at = submitted_at
        self.content = content

    def __str__(self):
        return f"Submission by {self.student_name} at {self.submitted_at}"


class Assignment:
    def __init__(self, title, description, due_date):
        self.title = title
        self.description = description
        self.due_date = due_date
        self.submissions: List[Submission] = []

    def __str__(self):
        return f"Assignment: {self.title}, Due: {self.due_date}"

    def run_autograder(self, submission_content: str) -> float:
        # pylint: disable=submission_content
        return 100.0  # Placeholder for actual grading logic

    def receive_submission(self, submission):
        if submission.submitted_at < self.due_date:
            # print("Warning: Submission is past the due date!")
            score: float = self.run_autograder(submission.content)
            submission.score = score
        self.submissions.append(submission)

    def get_most_recent_submission(self, student: str) -> Optional[Submission]:
        to_return: Optional[Submission] = None
        for sub in self.submissions:
            if sub.student_name == student and sub.score is not None:
                if to_return is None or sub.submitted_at > to_return.submitted_at:
                    to_return = sub
        return to_return
        # return max(self.submissions, key=lambda sub: sub.submitted_at)


if __name__ == "__main__":
    assignment1 = Assignment("Math Homework", "Complete exercises 1-10", "2024-05-01")
    submission1 = Submission("Alice", "2024-04-30 10:00", "Answers to exercises 1-10")

    print(assignment1)
    print(submission1)
