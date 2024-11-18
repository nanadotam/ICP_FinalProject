-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Host: localhost
-- Generation Time: Nov 18, 2024 at 02:41 PM
-- Server version: 10.4.28-MariaDB
-- PHP Version: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Database: `icp`
--

-- --------------------------------------------------------

--
-- Table structure for table `Courses`
--

CREATE TABLE `Courses` (
  `courseID` int(11) NOT NULL,
  `courseName` varchar(100) NOT NULL,
  `credits` int(11) NOT NULL,
  `schedule` enum('Semester1','Semester2') NOT NULL,
  `assignedFacultyID` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `Enrollment`
--

CREATE TABLE `Enrollment` (
  `enrollmentID` int(11) NOT NULL,
  `studentID` int(11) NOT NULL,
  `courseID` int(11) NOT NULL,
  `semester` enum('Semester1','Semester2') NOT NULL,
  `grade` varchar(5) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `Faculty`
--

CREATE TABLE `Faculty` (
  `facultyID` int(11) NOT NULL,
  `userID` int(11) NOT NULL,
  `dateOfAppointment` date DEFAULT NULL,
  `department` varchar(100) DEFAULT NULL,
  `listOfTeachingCourses` text DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `Grades`
--

CREATE TABLE `Grades` (
  `gradeID` int(11) NOT NULL,
  `studentID` int(11) NOT NULL,
  `courseID` int(11) NOT NULL,
  `gradeValue` varchar(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `Students`
--

CREATE TABLE `Students` (
  `studentID` int(11) NOT NULL,
  `userID` int(11) NOT NULL,
  `dateOfBirth` date DEFAULT NULL,
  `picture` varchar(255) DEFAULT NULL,
  `major` varchar(100) DEFAULT NULL,
  `enrollmentDate` date DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Table structure for table `Users`
--

CREATE TABLE `Users` (
  `userID` int(11) NOT NULL,
  `firstName` varchar(50) NOT NULL,
  `lastName` varchar(50) NOT NULL,
  `email` varchar(100) NOT NULL,
  `password` varchar(255) NOT NULL,
  `userType` enum('Student','Faculty','Administrator') NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Courses`
--
ALTER TABLE `Courses`
  ADD PRIMARY KEY (`courseID`),
  ADD KEY `assignedFacultyID` (`assignedFacultyID`);

--
-- Indexes for table `Enrollment`
--
ALTER TABLE `Enrollment`
  ADD PRIMARY KEY (`enrollmentID`),
  ADD KEY `studentID` (`studentID`),
  ADD KEY `courseID` (`courseID`);

--
-- Indexes for table `Faculty`
--
ALTER TABLE `Faculty`
  ADD PRIMARY KEY (`facultyID`),
  ADD KEY `userID` (`userID`);

--
-- Indexes for table `Grades`
--
ALTER TABLE `Grades`
  ADD PRIMARY KEY (`gradeID`),
  ADD KEY `studentID` (`studentID`),
  ADD KEY `courseID` (`courseID`);

--
-- Indexes for table `Students`
--
ALTER TABLE `Students`
  ADD PRIMARY KEY (`studentID`),
  ADD KEY `userID` (`userID`);

--
-- Indexes for table `Users`
--
ALTER TABLE `Users`
  ADD PRIMARY KEY (`userID`),
  ADD UNIQUE KEY `email` (`email`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `Courses`
--
ALTER TABLE `Courses`
  MODIFY `courseID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `Enrollment`
--
ALTER TABLE `Enrollment`
  MODIFY `enrollmentID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `Faculty`
--
ALTER TABLE `Faculty`
  MODIFY `facultyID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `Grades`
--
ALTER TABLE `Grades`
  MODIFY `gradeID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `Students`
--
ALTER TABLE `Students`
  MODIFY `studentID` int(11) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT for table `Users`
--
ALTER TABLE `Users`
  MODIFY `userID` int(11) NOT NULL AUTO_INCREMENT;

--
-- Constraints for dumped tables
--

--
-- Constraints for table `Courses`
--
ALTER TABLE `Courses`
  ADD CONSTRAINT `courses_ibfk_1` FOREIGN KEY (`assignedFacultyID`) REFERENCES `Faculty` (`facultyID`) ON DELETE SET NULL;

--
-- Constraints for table `Enrollment`
--
ALTER TABLE `Enrollment`
  ADD CONSTRAINT `enrollment_ibfk_1` FOREIGN KEY (`studentID`) REFERENCES `Students` (`studentID`) ON DELETE CASCADE,
  ADD CONSTRAINT `enrollment_ibfk_2` FOREIGN KEY (`courseID`) REFERENCES `Courses` (`courseID`) ON DELETE CASCADE;

--
-- Constraints for table `Faculty`
--
ALTER TABLE `Faculty`
  ADD CONSTRAINT `faculty_ibfk_1` FOREIGN KEY (`userID`) REFERENCES `Users` (`userID`) ON DELETE CASCADE;

--
-- Constraints for table `Grades`
--
ALTER TABLE `Grades`
  ADD CONSTRAINT `grades_ibfk_1` FOREIGN KEY (`studentID`) REFERENCES `Students` (`studentID`) ON DELETE CASCADE,
  ADD CONSTRAINT `grades_ibfk_2` FOREIGN KEY (`courseID`) REFERENCES `Courses` (`courseID`) ON DELETE CASCADE;

--
-- Constraints for table `Students`
--
ALTER TABLE `Students`
  ADD CONSTRAINT `students_ibfk_1` FOREIGN KEY (`userID`) REFERENCES `Users` (`userID`) ON DELETE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
