import React, { useState } from 'react';
import { 
  Container, 
  Typography, 
  Paper, 
  Divider, 
  Stack,
  Box,
  Button,
  TextField
} from '@mui/material';
import {
  List as AllTasksIcon,
  CheckCircle as DoneIcon,
  Schedule as ProgressIcon
} from '@mui/icons-material';
import ToggleButton from '@mui/material/ToggleButton';
import ToggleButtonGroup from '@mui/material/ToggleButtonGroup';
import { Add as AddIcon } from '@mui/icons-material';
import Task from './Task.js';

export default function TodoList() {
    const [filter, setFilter] = useState('all');
    const [newTaskTitle, setNewTaskTitle] = useState('');
    
    const tasks = [
        { id: 1, title: "Complete React Project", deadline: "2025-10-01", status: "progress" },
        { id: 2, title: "Review Code", deadline: "2025-10-02", status: "done" },
        { id: 3, title: "Write Documentation", deadline: "2025-10-03", status: "progress" },
    ];

    const handleFilterChange = (event, newFilter) => {
        if (newFilter !== null) {
            setFilter(newFilter);
        }
    };

    const handleAddTask = () => {
        if (newTaskTitle.trim()) {
            console.log('Adding new task:', newTaskTitle);
            // Here you would normally add the task to your tasks array
            setNewTaskTitle(''); // Clear the input
        }
    };

    const handleInputChange = (event) => {
        setNewTaskTitle(event.target.value);
    };

    const handleKeyPress = (event) => {
        if (event.key === 'Enter') {
            handleAddTask();
        }
    };


    return (
        <Container maxWidth="sm">
            <Paper 
                elevation={3}
                sx={{
                    padding: 4,
                    borderRadius: 3,
                    backgroundColor: 'white',
                    minWidth: 500
                }}
            >
                <Typography 
                    variant="h4" 
                    component="h1" 
                    gutterBottom
                    sx={{ 
                        textAlign: 'center',
                        fontWeight: 'bold',
                        marginBottom: 2
                    }}
                >
                    My Tasks
                </Typography>
                
                <Divider sx={{ marginBottom: 3 }} />
                
                <Box 
                    display="flex" 
                    justifyContent="center" 
                    sx={{ marginBottom: 3 }}
                >
                    <ToggleButtonGroup
                        value={filter}
                        exclusive
                        onChange={handleFilterChange}
                        aria-label="task filter"
                        size="small"
                        sx={{
                            backgroundColor: '#f5f5f5',
                            borderRadius: 2,
                            '& .MuiToggleButton-root': {
                                border: '1px solid #e0e0e0',
                                borderRadius: '8px !important',
                                margin: '2px',
                                textTransform: 'none',
                                fontWeight: 500,
                                minWidth: 100,
                                '&:hover': {
                                    backgroundColor: '#e3f2fd',
                                },
                                '&.Mui-selected': {
                                    backgroundColor: '#1976d2',
                                    color: 'white',
                                    '&:hover': {
                                        backgroundColor: '#1565c0',
                                    }
                                }
                            }
                        }}
                    >
                        <ToggleButton value="all" aria-label="all tasks">
                            <AllTasksIcon sx={{ marginRight: 1, fontSize: 18 }} />
                            All Tasks
                        </ToggleButton>
                        <ToggleButton value="done" aria-label="completed tasks">
                            <DoneIcon sx={{ marginRight: 1, fontSize: 18 }} />
                            Completed
                        </ToggleButton>
                        <ToggleButton value="progress" aria-label="tasks in progress">
                            <ProgressIcon sx={{ marginRight: 1, fontSize: 18 }} />
                            In Progress
                        </ToggleButton>
                    </ToggleButtonGroup>
                </Box>

                <Stack spacing={2}>
                    {tasks.map(task => (
                        <Task 
                            key={task.id}
                            title={task.title} 
                            deadline={task.deadline} 
                        />
                    ))}
                </Stack>
                
                <Box 
                    sx={{ 
                        marginTop: 3,
                        display: 'flex', 
                        gap: 2,
                        alignItems: 'center'
                    }}
                >
                    <TextField
                        fullWidth
                        variant="outlined"
                        label="Enter new task"
                        placeholder="What needs to be done?"
                        value={newTaskTitle}
                        onChange={handleInputChange}
                        onKeyPress={handleKeyPress}
                        size="small"
                        sx={{ flex: 1 }}
                    />
                    <Button
                        variant="contained"
                        startIcon={<AddIcon />}
                        onClick={handleAddTask}
                        disabled={!newTaskTitle.trim()}
                        sx={{
                            minWidth: 100,
                            height: '40px',
                            textTransform: 'none',
                            fontWeight: 600
                        }}
                    >
                        Add Task
                    </Button>
                </Box>
            </Paper>
        </Container>
    );
}