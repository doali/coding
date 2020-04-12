Feature:
  In order to manage server
  As an observer
  I want to check if the server is running whithout any error

  Scenario: server status
    Given an address and a port
    When I run the server
    Then the server status is RUNNING
