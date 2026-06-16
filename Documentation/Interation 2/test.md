# Testing Report - TP9

## Unit Tests


Result:

| Test Type | Result | Notes |
|---|---:|---|
| Unit Tests | 100% | 25 tests passed successfully |

## Integration Tests

| Use Case | Percentage | Notes |
|---|---:|---|
| UC 1 - Create Student | 100 | Student is created with valid data |
| UC 2 - List Students | 100 | Created students are listed correctly |
| UC 3 - Remove Student | 100 | Student is removed when not associated with a matricula |
| UC 4 - Create Training Plan | 100 | Training plan is created with valid data |
| UC 5 - List Training Plans | 100 | Created training plans are listed correctly |
| UC 6 - Remove Training Plan | 100 | Training plan is removed when not associated with a matricula |
| UC 7 - Create Matricula | 100 | Matricula is created with an existing student and training plan |
| UC 8 - List Matriculas | 100 | Created matriculas are listed correctly |
| UC 9 - Remove Student with Matricula | 100 | System prevents removal and throws DataConsistencyException |
| UC 10 - Remove Training Plan with Matricula | 100 | System prevents removal and throws DataConsistencyException |